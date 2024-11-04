# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# 定义链接选项
LDFLAGS = 

# 定义程序名
PROGRAM = main

# 定义报告的LaTeX文件和生成的PDF文件
REPORT_TEX = report.tex
REPORT_PDF = report.pdf

# 默认目标
all: $(PROGRAM)

# 编译并运行程序
run: $(PROGRAM)
	./$(PROGRAM)

# 编译报告并生成PDF
report:
	pdflatex $(REPORT_TEX)
	pdflatex $(REPORT_TEX) # 可能需要两次编译以解决引用问题

# 编译程序
$(PROGRAM): main.o 
	$(CXX) $(LDFLAGS) -o $@ $^

# 编译main.cpp
main.o: main.cpp BST.h
	$(CXX) $(CXXFLAGS) -c main.cpp


# 清理编译生成的文件
clean:
	rm -f *.o $(PROGRAM) $(REPORT_PDF)

.PHONY: all run report clean