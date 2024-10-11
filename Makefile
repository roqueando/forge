TARGET = rawr
BUILDDIR = build/debug

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

build: $(BUILDDIR)/Makefile
	@cmake --build build/debug

$(BUILDDIR)/Makefile:
	@cmake -DCMAKE_BUILD_TYPE=Debug -B build/debug

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
