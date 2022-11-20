NAME=ml_package
EXTRA_FLAGS=
WARN_FLAGS= \
	-Wfatal-errors \
	-Wshadow \
	-Wsign-compare \
	-Wundef \
	-Wwrite-strings \
	-Wredundant-decls \
	-Wdisabled-optimization \
	-Wdouble-promotion \
	-Wmissing-declarations \
	-Wno-reorder \
	-Wno-return-local-addr \
	-Wno-missing-declarations

COMPILE_FLAGS= -Wall -O2 $(WARN_FLAGS) -fno-stack-protector -fno-common $(EXTRA_FLAGS) -fpic
SRC_FILES=$(wildcard ./src/*.cpp)

INCLUDE_PATH="./include"

all:
	@mkdir -p ./bin
	@$(CC) -shared $(COMPILE_FLAGS) -I$(INCLUDE_PATH) $(SRC_FILES) -o ./bin/$(NAME).so
	@echo "Builded!"
clean:
	@rm -r ./bin
	@echo "Cleared!"
