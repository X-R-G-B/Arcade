FILES=$(find -name "*-prefix" -o -name "CMakeFiles" -o -name "CMakeCache.txt" -o -name "cmake_install.cmake" -o -name "*.so" -o -name "arcade" -o -name "Makefile")
echo "Files to clean: $FILES"
if [[ "$1" != "-y" ]]; then
    echo "Do you want to rm? (y/n)"
    read ANSWER
else
    ANSWER="y"
fi
if [ "$ANSWER" == "y" ]; then
    echo "Removing files..."
    rm -rf $FILES
else
    echo "Exiting..."
    exit
fi
echo "Done!"
