ifeq ($(strip $(PyGen_analyzerGenanalyzer)),)
PyGen_analyzerGenanalyzer := self/src/Gen_analyzer/Genanalyzer/python
src_Gen_analyzer_Genanalyzer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Gen_analyzer/Genanalyzer/python)
PyGen_analyzerGenanalyzer_files := $(patsubst src/Gen_analyzer/Genanalyzer/python/%,%,$(wildcard $(foreach dir,src/Gen_analyzer/Genanalyzer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGen_analyzerGenanalyzer_LOC_USE := self  
PyGen_analyzerGenanalyzer_PACKAGE := self/src/Gen_analyzer/Genanalyzer/python
ALL_PRODS += PyGen_analyzerGenanalyzer
PyGen_analyzerGenanalyzer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGen_analyzerGenanalyzer,src/Gen_analyzer/Genanalyzer/python,src_Gen_analyzer_Genanalyzer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGen_analyzerGenanalyzer,src/Gen_analyzer/Genanalyzer/python))
endif
ALL_COMMONRULES += src_Gen_analyzer_Genanalyzer_python
src_Gen_analyzer_Genanalyzer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Gen_analyzer_Genanalyzer_python,src/Gen_analyzer/Genanalyzer/python,PYTHON))
