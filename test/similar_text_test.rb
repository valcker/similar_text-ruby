require 'test_init.rb'

class SimilarTextTest < Test::Unit::TestCase
  def test_similar
    assert_equal(100.0, "Hello, World!".similar("Hello, World!"))
    assert_equal(96.0, "Hello, World!".similar("Hello World!"))
  end

  def test_similar_chars
    assert_equal(13, "Hello, World!".similar_chars("Hello, World!"))
    assert_equal(8, "Hello WORLD!".similar_chars("Hello, World!"))
  end
end

