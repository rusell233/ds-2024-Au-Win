# 定义编译器
CXX := g++

# 定义编译选项
CXXFLAGS := -std=c++11 -Wall

# 定义链接选项
LDFLAGS :=

# 定义可执行文件的名称
TARGET := List

# 默认目标
all: $(TARGET)

# 编译 List 程序
$(TARGET): list.cpp list.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) list.cpp $(LDFLAGS)

# 使用 xelatex 编译报告
report: report.tex
	xelatex report.tex
	@echo "Report generated: report.pdf"

# 清理生成的文件
clean:
	rm -f $(TARGET) report.aux report.log report.pdf
	@echo "Clean complete"

# 运行 make 时可以编译程序，并生成可执行文件 List
.PHONY: all clean