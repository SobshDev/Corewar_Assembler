# New ANSI colored banner for overall test runner
echo -e "\e[33m╔════════════════════════════════╗\e[0m"
echo -e "\e[33m║   🚀 RobotFactory Test Runner  ║\e[0m"
echo -e "\e[33m╚════════════════════════════════╝\e[0m"

# Log build start with ANSI art
echo -e "\e[36m╔═════════════════════════════╗\e[0m"
echo -e "\e[36m║   🚀🔧 Build Started...     ║\e[0m"
echo -e "\e[36m╚═════════════════════════════╝\e[0m"

make -s && make clean -s

# Log build end with ANSI art
echo -e "\e[35m╔═════════════════════════════╗\e[0m"
echo -e "\e[35m║   🎉✅ Build Ended...       ║\e[0m"
echo -e "\e[35m╚═════════════════════════════╝\e[0m"

cp asm Tester/my/
cd Tester

# Log test run start with ANSI art
echo -e "\e[33m╔════════════════════════════════════╗\e[0m"
echo -e "\e[33m║   🔥🧪🚀 Running Tests...          ║\e[0m"
echo -e "\e[33m╚════════════════════════════════════╝\e[0m"

./tester.sh
result=$?
if [ "$result" -eq 0 ]; then
    echo -e "\e[32m✔ Valid\e[0m"
elif [ "$result" -eq 1 ]; then
    echo -e "\e[31m✖ Error\e[0m"
fi
cd ..
rm asm