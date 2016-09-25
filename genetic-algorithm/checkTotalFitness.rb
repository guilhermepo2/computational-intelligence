file = ARGV[0]
time = ARGV[1]

fitness_total = 0
tempo = 0.0

File.readlines(file).each do |line|
  fitness_total = fitness_total + 1
end

File.readlines(time).each do |l|
  tempo = tempo + l.to_f
end

puts "Convergencia: #{fitness_total/10.0}%"
puts "Tempo total: #{tempo}"

exec ("rm " + file + "; rm " + time)
