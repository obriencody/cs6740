##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cs6740
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Cody/Documents/cs6740
ProjectPath            :=C:/Users/Cody/Documents/cs6740
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Cody
Date                   :=18/02/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="cs6740.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/decryptionTime.cpp$(ObjectSuffix) $(IntermediateDirectory)/decryptionTimeText.cpp$(ObjectSuffix) $(IntermediateDirectory)/employeeDir.cpp$(ObjectSuffix) $(IntermediateDirectory)/encryptDecrypt.cpp$(ObjectSuffix) $(IntermediateDirectory)/encryptionTime.cpp$(ObjectSuffix) $(IntermediateDirectory)/encryptionTimeText.cpp$(ObjectSuffix) $(IntermediateDirectory)/Source.cpp$(ObjectSuffix) $(IntermediateDirectory)/toolSetOptionsMain.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/decryptionTime.cpp$(ObjectSuffix): decryptionTime.cpp $(IntermediateDirectory)/decryptionTime.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/decryptionTime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/decryptionTime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/decryptionTime.cpp$(DependSuffix): decryptionTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/decryptionTime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/decryptionTime.cpp$(DependSuffix) -MM decryptionTime.cpp

$(IntermediateDirectory)/decryptionTime.cpp$(PreprocessSuffix): decryptionTime.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/decryptionTime.cpp$(PreprocessSuffix) decryptionTime.cpp

$(IntermediateDirectory)/decryptionTimeText.cpp$(ObjectSuffix): decryptionTimeText.cpp $(IntermediateDirectory)/decryptionTimeText.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/decryptionTimeText.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/decryptionTimeText.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/decryptionTimeText.cpp$(DependSuffix): decryptionTimeText.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/decryptionTimeText.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/decryptionTimeText.cpp$(DependSuffix) -MM decryptionTimeText.cpp

$(IntermediateDirectory)/decryptionTimeText.cpp$(PreprocessSuffix): decryptionTimeText.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/decryptionTimeText.cpp$(PreprocessSuffix) decryptionTimeText.cpp

$(IntermediateDirectory)/employeeDir.cpp$(ObjectSuffix): employeeDir.cpp $(IntermediateDirectory)/employeeDir.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/employeeDir.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/employeeDir.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/employeeDir.cpp$(DependSuffix): employeeDir.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/employeeDir.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/employeeDir.cpp$(DependSuffix) -MM employeeDir.cpp

$(IntermediateDirectory)/employeeDir.cpp$(PreprocessSuffix): employeeDir.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/employeeDir.cpp$(PreprocessSuffix) employeeDir.cpp

$(IntermediateDirectory)/encryptDecrypt.cpp$(ObjectSuffix): encryptDecrypt.cpp $(IntermediateDirectory)/encryptDecrypt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/encryptDecrypt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/encryptDecrypt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/encryptDecrypt.cpp$(DependSuffix): encryptDecrypt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/encryptDecrypt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/encryptDecrypt.cpp$(DependSuffix) -MM encryptDecrypt.cpp

$(IntermediateDirectory)/encryptDecrypt.cpp$(PreprocessSuffix): encryptDecrypt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/encryptDecrypt.cpp$(PreprocessSuffix) encryptDecrypt.cpp

$(IntermediateDirectory)/encryptionTime.cpp$(ObjectSuffix): encryptionTime.cpp $(IntermediateDirectory)/encryptionTime.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/encryptionTime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/encryptionTime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/encryptionTime.cpp$(DependSuffix): encryptionTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/encryptionTime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/encryptionTime.cpp$(DependSuffix) -MM encryptionTime.cpp

$(IntermediateDirectory)/encryptionTime.cpp$(PreprocessSuffix): encryptionTime.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/encryptionTime.cpp$(PreprocessSuffix) encryptionTime.cpp

$(IntermediateDirectory)/encryptionTimeText.cpp$(ObjectSuffix): encryptionTimeText.cpp $(IntermediateDirectory)/encryptionTimeText.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/encryptionTimeText.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/encryptionTimeText.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/encryptionTimeText.cpp$(DependSuffix): encryptionTimeText.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/encryptionTimeText.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/encryptionTimeText.cpp$(DependSuffix) -MM encryptionTimeText.cpp

$(IntermediateDirectory)/encryptionTimeText.cpp$(PreprocessSuffix): encryptionTimeText.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/encryptionTimeText.cpp$(PreprocessSuffix) encryptionTimeText.cpp

$(IntermediateDirectory)/Source.cpp$(ObjectSuffix): Source.cpp $(IntermediateDirectory)/Source.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/Source.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Source.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Source.cpp$(DependSuffix): Source.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Source.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Source.cpp$(DependSuffix) -MM Source.cpp

$(IntermediateDirectory)/Source.cpp$(PreprocessSuffix): Source.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Source.cpp$(PreprocessSuffix) Source.cpp

$(IntermediateDirectory)/toolSetOptionsMain.cpp$(ObjectSuffix): toolSetOptionsMain.cpp $(IntermediateDirectory)/toolSetOptionsMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Cody/Documents/cs6740/toolSetOptionsMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/toolSetOptionsMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/toolSetOptionsMain.cpp$(DependSuffix): toolSetOptionsMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/toolSetOptionsMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/toolSetOptionsMain.cpp$(DependSuffix) -MM toolSetOptionsMain.cpp

$(IntermediateDirectory)/toolSetOptionsMain.cpp$(PreprocessSuffix): toolSetOptionsMain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/toolSetOptionsMain.cpp$(PreprocessSuffix) toolSetOptionsMain.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


