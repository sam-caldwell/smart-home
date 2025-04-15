clean:
	clear
	rm -rf ./build
	make create_build_dir

create_build_dir:
	@mkdir -p ./build &> /dev/null

run: $(MAIN_EXEC)
	$(MAIN_EXEC)

test:
	$(TEST_EXEC)

tree:
	tree | sed 's/\xc2\xa0/ /g' > docs/file_structure.txt

zip:
	zip -r submission.zip ./
