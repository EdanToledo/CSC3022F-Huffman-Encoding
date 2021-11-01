# Instructions on how to use program

### Driver file : huffencode 
- to run type in terminal ./huffencode <flag: -c / -d> <Input File name> <Output File Name>

### FLAGS: <-c> or <-d>
- -c :This flag is used to specify to the program which input file you want compressed and what the name of the outputfile is called. The outputfile will automatically add the extension .bin.
	
- -d : This flag is used to specifiy to the program which compressed input file you want to decompress what the name of the decompressed file shall be called. To use this flag the inputfile name must be without the extension .bin so that the program knows to look for the .bin file and the .hdr header file that should be present.

### PARAMETERS: 
\<Input File Name\> this is the name of the file to be compressed or decompressed. As previously stated for only the decompress flag the input file name must be without any file name extensions (e.g. .bin) so that it can look for the .bin file and the .hdr file.

\<Output File Name\> this is the name that the output file shall be called. For the compress flag there is no need to add file extensions here either as when compressed .bin and .hdr will be added automatically to their respective files. For the Decompress flag the output name can be anything.

### NOTES:
The methods in the huffman tree class create temporary files for processing. The compress and decompress method use the necessary methods in conjunction and then remove the temporary files. The reason these methods were coded like this was so that each method could be used as a standalone function. But due to the nature of using the same parameters for input and output file names, these temporary files were given unique extensions that the function adds in automatically. An example is the .bin extension when bit packing or adding the word unpacked to the name of the file that is just bits in string format after a file is unpacked.

### Example on how to run:
*LEAVE OUT .bin EXTENSION FOR outputfile. it is added automatically along with its .hdr header file*
	
- ./huffencode -c inputfile.txt outputfile

*LEAVE OUT .bin extension for inputfile so program searches for inputfile.bin and inputfile.hdr*
	
- ./huffencode -d inputfile outputfile.txt


