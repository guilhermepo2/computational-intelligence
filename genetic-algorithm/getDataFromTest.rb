file = ARGV[0]
linhas = Array[]

File.readlines(file).each do |line|
  linhas.push(line)
end

todos_fitness = Array[]
todos_candidatos_menor_100 = Array[]
media_populacao = Array[]

for i in 0..linhas.size()-1
  if (linhas[i].include? "Fitness: ")
    todos_fitness.push(linhas[i])
  end

  if(linhas[i].include? "Candidates with fitness < 100: ")
    todos_candidatos_menor_100.push(linhas[i])
  end

  if(linhas[i].include? "Populations' mean fitnes: ")
    media_populacao.push(linhas[i])
  end
end

# agora tudo da geracao 0 estao nos pares
# e os da geracao 1 estao nos impares
fitness_g0 = 0
fitness_g1 = 0
candidatos_menor_100_g0 = 0
candidatos_menor_100_g1 = 0
media_pop_g0 = 0
media_pop_g1 = 0

for i in 0..todos_fitness.size()-1
  if i % 2 == 0
    fitness_g0 = fitness_g0 + (todos_fitness[i].delete! 'Fitness: ').to_i
    candidatos_menor_100_g0 = candidatos_menor_100_g0 + (todos_candidatos_menor_100[i].delete! 'Candidates with fitness < 100: ').to_i
    media_pop_g0 = media_pop_g0 + (media_populacao[i].delete! "Populations' mean fitnes: ").to_i
  else
    fitness_g1 = fitness_g1 + (todos_fitness[i].delete! 'Fitness: ').to_i
    candidatos_menor_100_g1 = candidatos_menor_100_g1 + (todos_candidatos_menor_100[i].delete! 'Candidates with fitness < 100: ').to_i
    media_pop_g1 = media_pop_g1 + (media_populacao[i].delete! "Populations' mean fitnes: ").to_i
  end
end

media_g0 = 100000 - (fitness_g0 / (todos_fitness.size() / 2.0))
media_g1 =  100000 - (fitness_g1 / (todos_fitness.size() / 2.0))
media_menor_100_g0 = (candidatos_menor_100_g0 / (todos_candidatos_menor_100.size() / 2.0))
media_menor_100_g1 = (candidatos_menor_100_g1 / (todos_candidatos_menor_100.size() / 2.0))
media_media_pop_g0 = (media_pop_g0 / (media_populacao.size() / 2.0))
media_media_pop_g1 = (media_pop_g1 / (media_populacao.size() / 2.0))

puts "Media fitness geracao 0: #{media_g0}"
puts "Media fitness geracao 1: #{media_g1}"
puts "Media menores que 100 geracao 0: #{media_menor_100_g0}"
puts "Media menores que 100 geracao 1: #{media_menor_100_g1}"
puts "Media Populacao em G0: #{media_media_pop_g0}"
puts "Media Populacao em G1: #{media_media_pop_g1}"
