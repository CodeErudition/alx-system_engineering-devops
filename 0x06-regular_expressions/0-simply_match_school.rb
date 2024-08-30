#!/usr/bin/env ruby
# The script accepts one argument (ARGV[0]) and uses it for regex matching.

puts ARGV[0].scan(/School/).join
