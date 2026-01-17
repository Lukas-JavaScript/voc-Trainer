cd ..
g++ main.cpp components/start/start.cpp components/used_choice.cpp components/exit_program.cpp components/add.cpp components/start_test.cpp -o Linux/main && \
x86_64-w64-mingw32-g++ main.cpp components/start/start.cpp components/used_choice.cpp components/exit_program.cpp components/add.cpp components/start_test.cpp -o Windows/64-Bit/main.exe -static-libgcc -static-libstdc++ && \
i686-w64-mingw32-g++ main.cpp components/start/start.cpp components/used_choice.cpp components/exit_program.cpp components/add.cpp components/start_test.cpp -o Windows/32-Bit/main.exe -static-libgcc -static-libstdc++ && \
cd automatations && \
echo "Compilation complete!" 