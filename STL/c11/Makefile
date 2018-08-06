SOURCE = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp,%.o,$(SOURCE))

TARGET  := cpp11

CXXFLAGS +=  -g -Wall -std=c++11 -lpthread
# 编译规则		
all: EHO $(OBJS)  
	echo $(SOURCE)
	echo $(OBJS)
#	$(CXX) ${CXXFLAGS}  -o  $(OBJS)

PHONY : clean install EHO
clean :
	-rm   *.o *.so

# 生成  目标文件
install:
	$(CXX) ${CXXFLAGS}  ${SHARE}  -o ${TARGET} $(OBJS)

	
EHO:
	echo ${LpfExport}
	@echo $(SOURCE)
	@echo $(OBJS)
	echo ${CXXFLAGS}
	echo ${SHARE}
	echo ${BUID_DIR}