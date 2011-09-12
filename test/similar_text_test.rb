require 'test_init.rb'

class SimilarTextTest < Test::Unit::TestCase
  def test_similar
    assert_equal(100.0, "Hello, World!".similar("Hello, World!"))
    assert_equal(96.0, "Hello, World!".similar("Hello World!"))
  end

  def test_similar?
    assert_equal(true, "Hello, World!".similar?("Hello, World!"))
    assert_equal(false, "Hello WORLD!".similar?("Hello, World!"))
  end
end

