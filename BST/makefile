# 定义编译器
CXX = g++
# 定义编译选项
CXXFLAGS = -O2

# 定义xelatex编译器
XELATEX = xelatex

# 默认目标
all: run

# 编译并链接生成可执行文件，并运行程序
run: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test
	./test

# 编译report.tex文件
report: report.tex
	$(XELATEX) report.tex

# 清理生成的可执行文件和PDF文件
clean:
	rm -f test
	rm -f report.pdf

# 伪目标，确保在运行前先编译
.PHONY: all run report clean