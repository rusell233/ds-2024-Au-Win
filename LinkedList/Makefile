# 编译器
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# 源文件和目标文件
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# 可执行文件
TARGET = program

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 生成对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f $(OBJS) $(TARGET)

# 运行程序
run: $(TARGET)
	@echo "Running the program..."
	./$(TARGET)

# 声明伪目标
.PHONY: all clean run
