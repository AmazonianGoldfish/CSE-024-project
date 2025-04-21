# ========================================================================================= #
#  Bobcat UI Application Makefile      														#
#  Angelo Kyrilov                      														#
#  University of California, Merced    												   		#
# ========================================================================================= #

# ===================================== PROJECT CONFIG ==================================== #

SRC_DIR = src
TEST_DIR = test

OBJ_DIR = objects
LOCAL_BIN_DIR = bin

APP = app
MAIN = main
TEST = test

# =================================== COMPILER SETTINGS =================================== #

CXX = g++

CXXFLAGS = -Wall
LDFLAGS = -lfltk_images -lpng -lz -lfltk_gl -lGLU -lGL -lfltk -lXrender \
          -lXext -lXft -lfontconfig -lpthread -ldl -lm -lX11

# ==================================== OTHER SETTINGS ===================================== #

LOCAL_DIR := $(PWD)
BIN_DIR = /tmp/$(LOCAL_BIN_DIR)$(LOCAL_DIR)

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OUT = $(BIN_DIR)/$(APP)

TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(TEST_SRC:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OUT = $(BIN_DIR)/$(TEST)

HEADERS = $(wildcard $(SRC_DIR)/*.h)

MAKEFLAGS += --no-print-directory

CURRENT_BRANCH = $(shell git rev-parse --abbrev-ref HEAD)

all: $(OUT)

$(OUT): $(OBJ) $(BIN_DIR) $(LOCAL_BIN_DIR)
	$(CXX) $(OBJ) -o $(OUT) $(LDFLAGS)
	@rm -f $(LOCAL_BIN_DIR)/$(APP)
	@ln -s $(OUT) $(LOCAL_BIN_DIR)/$(APP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(LOCAL_BIN_DIR):
	@mkdir -p $(LOCAL_BIN_DIR)

run: $(OUT)
	clear
	@$(LOCAL_BIN_DIR)/$(APP)

test: $(OBJ) $(TEST_OBJ) $(BIN_DIR) $(LOCAL_BIN_DIR) 
	$(CXX) $(filter-out $(OBJ_DIR)/$(MAIN).o, $(OBJ)) $(TEST_OBJ) -o $(TEST_OUT) $(LDFLAGS)
	@rm -f $(LOCAL_BIN_DIR)/$(TEST)
	@ln -s $(TEST_OUT) $(LOCAL_BIN_DIR)/$(TEST)
	@clear
	$(LOCAL_BIN_DIR)/$(TEST) --output=color || true

autograde: clean $(OBJ) $(TEST_OBJ) $(BIN_DIR) $(LOCAL_BIN_DIR) 
	@$(CXX) $(filter-out $(OBJ_DIR)/$(MAIN).o, $(OBJ)) $(TEST_OBJ) -o $(TEST_OUT) $(LDFLAGS)
	@rm -f $(LOCAL_BIN_DIR)/$(TEST)
	@ln -s $(TEST_OUT) $(LOCAL_BIN_DIR)/$(TEST)
	@xvfb-run $(LOCAL_BIN_DIR)/$(TEST) || true

$(OBJ_DIR)/$(TEST).o: $(TEST_DIR)/$(TEST).cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/$(TEST).cpp -o $(OBJ_DIR)/$(TEST).o

pull:
ifeq ($(shell git rev-parse --is-inside-work-tree 2>/dev/null),true)
	@git reset --hard
	@git clean -fdx
	@git pull origin $(CURRENT_BRANCH) --ff-only
else
	@echo "No git repository found in the current directory"
endif

clean:
	@rm -f $(LOCAL_BIN_DIR)/$(APP) $(OBJ) $(LOCAL_BIN_DIR)/$(TEST) $(TEST_OBJ)
	@rmdir $(LOCAL_BIN_DIR) $(OBJ_DIR) 2> /dev/null || true

.PHONY: run pull test clean
