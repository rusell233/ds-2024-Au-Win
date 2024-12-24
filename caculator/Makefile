# Makefile

# 定义编译器和编译选项
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# 定义xelatex命令
XELATEX := xelatex

# 定义目标文件和源文件
TARGET := main
SOURCES := main.cpp calculator.cpp
HEADERS := calculator.h

# 定义 Phony 目标
.PHONY: run report clean

# 默认目标
all: run

# 编译并运行程序
run: $(TARGET)
	./$(TARGET)

# 链接目标文件和源文件
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 使用 xelatex 编译 LaTeX 文档
report:
	$(XELATEX) report.tex
	$(XELATEX) report.tex

# 清理生成的文件
clean:
	rm -f $(TARGET) report.pdf report.aux report.log