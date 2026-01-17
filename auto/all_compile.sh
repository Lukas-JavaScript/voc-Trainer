cd ..
g++ main.cpp components/start.cpp -o Linux/main && \
x86_64-w64-mingw32-g++ main.cpp components/start.cpp -o Windows/64-Bit/main.exe -static-libgcc -static-libstdc++ && \
i686-w64-mingw32-g++ main.cpp components/start.cpp -o Windows/32-Bit/main.exe -static-libgcc -static-libstdc++ && \
cd auto && \
echo "Compilation complete!" 