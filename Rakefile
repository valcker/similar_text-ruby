require "bundler/gem_tasks"
require 'rubygems'
require 'rake'
require 'rake/extensiontask'

Rake::ExtensionTask.new("similar_text") do |extension|
	  extension.lib_dir = "lib/similar_text"
end

task :chmod do
	  File.chmod(0775, 'lib/similar_text/similar_text.so')
end
task :build => [:clean, :compile, :chmod]

Bundler::GemHelper.install_tasks

