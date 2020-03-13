# CSC3022F-Huffman-Encoding
C++ implementation of a huffman tree and encoding - Compress and Decompress text files
README - Instructions on how to use program

**********************************************************************************************************************************
Driver file : huffencode - to run type in terminal ./huffencode <flag: -c / -d> <Input File name> <Output File Name>
**********************************************************************************************************************************

**********************************************************************************************************************************
FLAGS: <-c> or <-d>
-c :This flag is used to specify to the program which input file you want compressed and what the name of the outputfile is called. The outputfile will automatically add the extension .bin.
	
-d : This flag is used to specifiy to the program which compressed input file you want to decompress what the name of the decompressed file shall be called. To use this flag the inputfile name must be without the extension .bin so that the program knows to look for the .bin file and the .hdr header file that should be present.
**********************************************************************************************************************************

**********************************************************************************************************************************
PARAMETERS: 
<Input File Name> this is the name of the file to be compressed or decompressed. As previously stated for only the decompress flag the input file name must be without any file name extensions (e.g. .bin) so that it can look for the .bin file and the .hdr file.

<Output File Name> this is the name that the output file shall be called. For the compress flag there is no need to add file extensions here either as when compressed .bin and .hdr will be added automatically to their respective files. For the Decompress flag the output name can be anything.
**********************************************************************************************************************************

Example on how to run:
./huffencode -c inputfile.txt outputfile

./huffencode -d inputfile outputfile.txt
