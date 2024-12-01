# Makefile

# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -std=c++11 -Wall -O2

# 定义链接选项
LDFLAGS = 

# 定义要编译的源文件
SOURCES = test.cpp

# 生成可执行文件的名称
EXECUTABLE = test

# 默认目标
all: $(EXECUTABLE)

# 编译并生成可执行文件 test
$(EXECUTABLE): $(SOURCES) HeapSort.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

# 运行测试并生成报告
report: $(EXECUTABLE)
	./$(EXECUTABLE) > report.txt

# 清理生成的文件
clean:
	rm -f $(EXECUTABLE) report.txt

# 伪目标，确保在新命令执行前先执行此命令
.PHONY: all clean report