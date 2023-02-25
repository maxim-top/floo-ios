1. ubuntu系统内下载代码：https://github.com/maxep/swig-objc
2. 构建swig-objc，生成swig可执行文件，增加swig目录到环境变量PATH
3. 将floo/inclue复制到当前目录下
4. bash preprocess.sh
5. swig  -debug-classes -debug-module 4 -debug-typemap  -c++ -objc  -Ifloo/include floo.i
6. 将生成的floo_proxy.h floo_proxy.mm floo_wrap.h floo_wrap.mm复制到macOS系统
6. bash post-swig.sh
7. 将floo_proxy.h floo_proxy.mm floo_wrap.h floo_wrap.mm添加到floo-ios项目中