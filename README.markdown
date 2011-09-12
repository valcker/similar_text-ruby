Ruby similar_text
=================

Port of PHP similar_text function to Ruby, built as a native extension.

INSTALL
=======

You can install this extension via gems:

        $ sudo gem install similar_text

USAGE
=====

Load extension:

	require 'similar_text'

And use it by calling one of two methods (similar or similar?):

	"Hello, World!".similar("Hello World!") # 96.0
	"Hello, World!".similar?(Hello World!") # false

