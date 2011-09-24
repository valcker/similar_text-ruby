# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "similar_text/version"

Gem::Specification.new do |s|
  s.name        = "similar_text"
  s.version     = SimilarText::VERSION
  s.authors     = ["Arthur Murauskas"]
  s.email       = ["arthur.murauskas@gmail.com"]
  s.homepage    = "http://github.com/valcker/similar_text-ruby"
  s.summary     = %q{Port of PHP function similar_text to Ruby as a native extension. Adds methods similar and similar_chars to core String class.}
  s.description = %q{Port of PHP function similar_text to Ruby as a native extension. Adds methods similar and similar_chars to core String class.}

  s.rubyforge_project = "similar_text"
  
  s.extra_rdoc_files = ['README.markdown', 'CHANGELOG.rdoc']
  s.rdoc_options = ['-m', 'README.markdown', '-x', 'lib/similar_text/version.rb']

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths << "lib"
  s.extensions << "ext/similar_text/extconf.rb"

  # specify any dependencies here; for example:
  # s.add_development_dependency "rspec"
  # s.add_runtime_dependency "rest-client"
end
