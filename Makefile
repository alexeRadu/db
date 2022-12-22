TARGET  := bd
BUILDIR := build

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=$(BUILDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "[LD] $@"
	@$(CXX) $^ -o $@

$(BUILDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "[CC] $<"
	@$(CXX) -c $< -o $@

db:
	-@bear --output $(BUILDIR)/compile_commands.json -- make

.PHONY: clean
clean:
	@for file in $(OBJS) $(TARGET); do	\
		if [ -f $${file} ]; then		\
			echo "[RM] $${file}";		\
			rm $${file};				\
		fi								\
	done
	@rm -Rf $(BUILDIR)
