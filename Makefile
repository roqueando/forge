TARGET = forge
BUILDDIR = build/debug
SRCDIR = src

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

build: $(BUILDDIR)/Makefile
	@cmake --build build/debug
	@ln -sf $(BUILDDIR)/compile_commands.json .

$(BUILDDIR)/Makefile:
	@cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 -B build/debug 

# check and watch is for development purposes
# you'll need to be installing cppcheck and inotify-tools
check:
	@echo "running cppcheck..."
	cppcheck $(SRCDIR)

watch:
	@echo "watching for changes in $(SRCDIR)..."
	while inotifywait -e modify -r ./src ./include; do \
		$(MAKE) check; \
	done

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
