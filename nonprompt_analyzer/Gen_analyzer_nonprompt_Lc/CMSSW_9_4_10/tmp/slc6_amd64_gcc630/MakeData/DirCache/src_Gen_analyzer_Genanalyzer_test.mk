ALL_COMMONRULES += src_Gen_analyzer_Genanalyzer_test
src_Gen_analyzer_Genanalyzer_test_parent := Gen_analyzer/Genanalyzer
src_Gen_analyzer_Genanalyzer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Gen_analyzer_Genanalyzer_test,src/Gen_analyzer/Genanalyzer/test,TEST))
