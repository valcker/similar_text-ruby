Ruby similar_text
=================

Calculate the similarity between two strings. Port of PHP similar_text function to Ruby, built as a native extension.

Description from php.net:

	This calculates the similarity between two strings as described in Oliver [1993]. Note that this implementation does not use a stack as in Oliver's pseudo code, but recursive calls which may or may not speed up the whole process. Note also that the complexity of this algorithm is O(N**3) where N is the length of the longest string.

INSTALL
=======

You can install this extension via gems:

        $ sudo gem install similar_text

USAGE
=====

Load extension:

	require 'similar_text'

And use it by calling one of two methods (similar or similar_chars):

	"Hello, World!".similar("Hello World!") #=> 96.0
	"Hello, World!".similar_chars("Hello World!") #=> 12

