.PHONY: clean All

All:
	@echo "----------Building project:[ cs6740 - Debug ]----------"
	@"$(MAKE)" -f  "cs6740.mk"
clean:
	@echo "----------Cleaning project:[ cs6740 - Debug ]----------"
	@"$(MAKE)" -f  "cs6740.mk" clean
