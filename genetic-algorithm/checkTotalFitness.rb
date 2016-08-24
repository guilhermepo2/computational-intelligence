file = ARGV[0]
fitness_total = 0

File.readlines(file).each do |line|
  fitness_total = fitness_total + 1
end

puts fitness_total
