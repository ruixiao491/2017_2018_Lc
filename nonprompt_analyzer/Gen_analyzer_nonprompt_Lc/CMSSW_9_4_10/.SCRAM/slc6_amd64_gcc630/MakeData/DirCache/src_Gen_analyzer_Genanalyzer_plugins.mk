ifeq ($(strip $(Gen_analyzerGenanalyzerAuto)),)
Gen_analyzerGenanalyzerAuto := self/src/Gen_analyzer/Genanalyzer/plugins
PLUGINS:=yes
Gen_analyzerGenanalyzerAuto_files := $(patsubst src/Gen_analyzer/Genanalyzer/plugins/%,%,$(wildcard $(foreach dir,src/Gen_analyzer/Genanalyzer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
Gen_analyzerGenanalyzerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Gen_analyzer/Genanalyzer/plugins/BuildFile
Gen_analyzerGenanalyzerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CommonTools/UtilAlgos
Gen_analyzerGenanalyzerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,Gen_analyzerGenanalyzerAuto,Gen_analyzerGenanalyzerAuto,$(SCRAMSTORENAME_LIB),src/Gen_analyzer/Genanalyzer/plugins))
Gen_analyzerGenanalyzerAuto_PACKAGE := self/src/Gen_analyzer/Genanalyzer/plugins
ALL_PRODS += Gen_analyzerGenanalyzerAuto
Gen_analyzer/Genanalyzer_forbigobj+=Gen_analyzerGenanalyzerAuto
Gen_analyzerGenanalyzerAuto_INIT_FUNC        += $$(eval $$(call Library,Gen_analyzerGenanalyzerAuto,src/Gen_analyzer/Genanalyzer/plugins,src_Gen_analyzer_Genanalyzer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
Gen_analyzerGenanalyzerAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,Gen_analyzerGenanalyzerAuto,src/Gen_analyzer/Genanalyzer/plugins))
endif
ALL_COMMONRULES += src_Gen_analyzer_Genanalyzer_plugins
src_Gen_analyzer_Genanalyzer_plugins_parent := Gen_analyzer/Genanalyzer
src_Gen_analyzer_Genanalyzer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Gen_analyzer_Genanalyzer_plugins,src/Gen_analyzer/Genanalyzer/plugins,PLUGINS))
