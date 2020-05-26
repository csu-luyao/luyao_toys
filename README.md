# luyao_toys
### There are some school assignments and toys.  
* **EncryptionByHFMTree** is a project that can encode and decode a text.The following is its functions:
  * I: Initialize. Read the character set size n from the terminal, as well as n characters and n weights, build a Huffman tree, and store it in the file hfmTree.
  * E: coding. Use the built Huffman tree (if not in memory, read from the file htmTree), encode the text in the file ToBeTran, and then save the result in the file CodeFile.
  * D: Decoding. Use the established Huffman tree to decode the code in the file CodeFile, and store the result in the file TextFile.
  * P: Print code file. The file CodeFile is displayed on the terminal in a compact format with 50 codes per line. At the same time, the encoding in the form of characters is written into the file CodePrint.
  * T: Print Huffman tree. The Huffman tree already in memory is displayed on the terminal in an intuitive manner (in the form of a tree or a concave table), and at the same time, the Huffman tree in the form of this character is written to the file TreePrint.
