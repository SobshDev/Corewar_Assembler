#!/bin/bash
# New ANSI colored banner for Tester
echo -e "\e[36m╔════════════════════════════════════════╗\e[0m"
echo -e "\e[36m║       ✨ RobotFactory Tester ✨        ║\e[0m"
echo -e "\e[36m╚════════════════════════════════════════╝\e[0m"

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Create directories if they don't exist
mkdir -p ref_tmp my_tmp

# Function to clean .cor files
clean_cor_files() {
    rm -f ref_tmp/*.cor my_tmp/*.cor
}

# Clean before starting
clean_cor_files

total=0
passed=0

# Compile all .s files with both ASMs
for s_file in champions/*.s; do
    if [ -f "$s_file" ]; then
        total=$((total+1))
        filename=$(basename "$s_file")
        #echo "Testing: $filename"
        
        # Run reference ASM from the "reference" folder
        cd reference || exit
        ref_output=$(./asm "../champions/$filename" 2>&1)
        ref_rc=$?
        if [ $ref_rc -eq 0 ] && [ -f "${filename%.*}.cor" ]; then
            mv "${filename%.*}.cor" "../ref_tmp/"
            cd .. || exit
            
            # Run your ASM from the "my" folder
            cd my || exit
            my_output=$(./asm "../champions/$filename" 2>&1)
            my_rc=$?
            if [ $my_rc -eq 0 ] && [ -f "${filename%.*}.cor" ]; then
                mv "${filename%.*}.cor" "../my_tmp/"
                cd .. || exit
                
                # Compare binaries
                if diff "ref_tmp/${filename%.*}.cor" "my_tmp/${filename%.*}.cor" > /dev/null; then
                    passed=$((passed+1))
                    #echo -e "${GREEN}✓ $filename: Files match${NC}"
                else
                    echo -e "${RED}✗ $filename: Files differ${NC}"
                    echo -e "${RED}Hexdump comparison:${NC}"
                    echo -e "${GREEN}Reference ASM output:${NC}"
                    hexdump -C "ref_tmp/${filename%.*}.cor"
                    echo -e "${RED}Your ASM output:${NC}"
                    hexdump -C "my_tmp/${filename%.*}.cor"
                fi
            else
                cd .. || exit
                echo -e "${RED}✗ $filename: Your ASM failed to compile (expected success)${NC}"
            fi
        else
            cd .. || exit
            # Reference ASM failed: run My ASM to compare exit codes and outputs.
            cd my || exit
            my_output=$(./asm "../champions/$filename" 2>&1)
            my_rc=$?
            cd .. || exit
            if [ $ref_rc -eq 84 ] && [ $my_rc -eq 84 ]; then
                passed=$((passed+1))
            else
                echo -e "${RED}✗ $filename: For failed compilation, results differ${NC}"
                echo -e "${GREEN}Reference ASM exit code: $ref_rc, output:${NC}"
                echo "$ref_output"
                echo -e "${RED}Your ASM exit code: $my_rc, output:${NC}"
                echo "$my_output"
            fi
        fi
    fi
done

echo -e "${GREEN}$passed out of $total tests passed${NC}"
echo -e "\e[38;2;255;105;180m╔════════════════════════════════╗\e[0m"
echo -e "\e[38;2;255;105;180m║  Made By Gabriel BRUMENT 2025  ║\e[0m"
echo -e "\e[38;2;255;105;180m╚════════════════════════════════╝\e[0m"

clean_cor_files

if [ "$passed" -eq "$total" ]; then
    exit 0
else
    exit 1
fi