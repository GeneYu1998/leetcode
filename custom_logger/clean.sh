if [ -d build ]; then
    rm -rf build
fi
if [ -f output ]; then
    rm output
fi
echo "build and output cleaned! :D"