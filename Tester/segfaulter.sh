#!/bin/bash

# New ANSI colored banner for Segfault Checker
echo -e "\e[35m╔════════════════════════════════════════╗\e[0m"
echo -e "\e[35m║   ⚠ RobotFactory Segfault Checker ⚠   ║\e[0m"
echo -e "\e[35m╚════════════════════════════════════════╝\e[0m"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "Checking for segmentation faults..."

segfault_count=0
total_files=0

# Test all .s files
for s_file in champions/*.s; do
    if [ -f "$s_file" ]; then
        total_files=$((total_files+1))
        filename=$(basename "$s_file")
        
        # Run your ASM with champion data from file
        cd my || exit
        ./asm "../champions/$filename" 2>&1
        
        # Check if the program segfaulted
        if [ $? -eq 139 ]; then
            segfault_count=$((segfault_count+1))
            echo -e "${RED}Segmentation fault detected on: $filename${NC}"
        else
            echo -e "${GREEN}✓ $filename: No segfault${NC}"
        fi
        cd .. || exit
    fi
done

echo -e "${RED}Found $segfault_count segfaults out of $total_files files tested${NC}"
echo -e "${GREEN}Segfault check complete${NC}"
