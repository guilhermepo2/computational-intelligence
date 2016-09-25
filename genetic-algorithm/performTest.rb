def performTest(word1, word2, word3, pop, gen, psize, cross, mut, q_tests)
  string_test = ""
  for_string = ""

  string_test = "./cryptoarithmetic " + word1 + " " + word2 + " " + word3 + " " + pop.to_s + " " + gen.to_s + " " + psize.to_s + " " + " " + cross.to_s + " " + mut.to_s + " "
  
  for_string = "for i in {0.." + (q_tests-1).to_s + "}; do " + string_test + "; done;"

  #puts string_test
  #puts for_string
  exec for_string
end

# teste para convergencia, 50 geracoes, 1000 vezes
#            XXXX +  XXXX  = XXXXX   pop ger tam cross mutac  vezes
performTest("SEND", "MORE", "MONEY", 200, 1000, 10, 0.80, 0.25, 1000)
