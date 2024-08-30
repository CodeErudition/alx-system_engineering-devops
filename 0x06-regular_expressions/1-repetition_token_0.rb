#!/usr/bin/env ruby
# This regular expression matchs the listed cases

puts ARGV[0].scan(/hbt{2,5}n/).join
