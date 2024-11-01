TARGET = <project_name>
BUILDDIR = build/debug
SRCDIR = src

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

build: $(BUILDDIR)/Makefile
	@cmake --build build/debug
	@ln -sf $(BUILDDIR)/compile_commands.json .

$(BUILDDIR)/Makefile:
	@cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 -B build/debug 

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
