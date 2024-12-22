# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -Wall -std=c++11

# 定义目标文件
TARGET = calculator

# 定义源文件
SOURCES = main.cpp

# 定义对象文件
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJECTS) $(TARGET)

# 伪目标，以便在没有目标文件时执行
.PHONY: all clean