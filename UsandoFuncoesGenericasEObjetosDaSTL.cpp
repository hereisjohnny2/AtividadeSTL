#include <iostream>   // Entrada e saída de dados
#include <iomanip>    // Manipuladores
#include <string>     // Strings de C++
#include <vector>     // Classe de vetores
#include <algorithm>  // Classe para algoritmos gen�ricos
#include <memory>     // destroe e construct
#include <cstdlib>    // Função rand
#include <numeric>    // Função inner_product
#include <functional> // Função
#include <iterator>   // Iteradores
#include <cctype>     //
#include <deque>      //

using namespace std; // Define o uso do espaço de nomes std

/** Classe para teste dos algoritmos genéricos */
class CTesteFuncoesGenericas
{
public:
  vector<int> v, v2, v3; // Atributos
  string msg;
  CTesteFuncoesGenericas() // Construtor
  {
    InicializaVetor(v); // Preenche o vetor v com valores
    v3 = v2 = v;
    msg = "\n-------------------------------------------\n";
  }

  // Métodos públicos
  void EntradaUsuario(vector<int> &vetor);
  void InicializaVetor(vector<int> &vetor, int n = 5);
  bool Run();

private:                // Métodos privados
  void Uso_de_fill_n(); // Preenchimento
  void Uso_de_equal();  // Comparação
  void Uso_de_mismatch();
  void Uso_de_includes();
  void Uso_de_remove_copy_if();  // Remoção
  void Uso_de_replace_copy_if(); // Trocas
  void Uso_de_inplace_merge();   // Misturar/mesclar/inverter
  void Uso_de_reverse_copy();
  void Uso_de_random_shuffle();
  void Uso_de_find_if_off(); // Pesquisa
  void Uso_de_adjacent_difference();
  void Uso_de_search_n();
  void Uso_de_binary_search();
  void Uso_de_advance();
  void Uso_de_next_permutation(); // Ordenação
  void Uso_de_reverse();
  void Uso_de_rotate();
  void Uso_de_generate(); // Transformação
  void Uso_de_for_each();
  void Uso_de_transform();
  void Uso_de_nth_element(); // Matemáticos
  void Uso_de_counf_if();
  void Uso_de_accumulate();
  void Uso_de_inner_product();
  void Uso_de_set_union();
  void Uso_de_set_intersection();
  void Uso_de_set_difference();
  void Uso_de_set_symmetric_difference();
  void Uso_de_make_heap(); // Ordenação por pilha
  void Uso_de_plus();      // Funções objeto
  void Uso_de_minus();
  void Uso_de_times();
  void Uso_de_multiplies();
  void Uso_de_divides();
  void Uso_de_modulus();
  void Uso_de_negate();
  void Uso_de_equal_to();
  void Uso_de_not_equal_to();
  void Uso_de_greater();
  void Uso_de_less();
  void Uso_de_greater_equal();
  void Uso_de_less_equal();
  void Uso_de_logical_and(); // Funções lógicas
  void Uso_de_logical_or();
  void Uso_de_logical_not();
  void Uso_de_bind2nd(); // Adaptadores (not1 find_if)
  void Uso_de_men_fun_ref(const vector<string> &s);

  void Uso_de_none_of();
  void Uso_de_adjacent_find();
  void Uso_de_copy();
  void Uso_de_swap_ranges();
  void Uso_de_generate_n();
  void Uso_de_unique();
  void Uso_de_is_partitioned();
  void Uso_de_partition_point();
  void Uso_de_partial_sort_copy();
  void Uso_de_upper_bound();
  void Uso_de_push_heap();
  void Uso_de_is_heap_until();
  void Uso_de_min_element();
  void Uso_de_prev_permutation();

  void Uso_de_find();
  void Uso_de_count();
  void Uso_de_copy_n();
  void Uso_de_iter_swap();
  void Uso_de_remove();
  void Uso_de_unique_copy();
  void Uso_de_partition();
  void Uso_de_sort();
  void Uso_de_is_sorted();
  void Uso_de_equal_range();
  void Uso_de_pop_heap();
  void Uso_de_min();
  void Uso_de_max_element();
}; // fim da classe

bool CNumeroImpar(int i)
{
  return ((i % 2) == 1);
}

bool CNumeroPar(int i)
{
  return ((i % 2) == 0);
}
bool Positivo(int i)
{
  return i > 0;
}

bool Negativo(int i)
{
  return i < 0;
}

// Solicita valores do vetor
void CTesteFuncoesGenericas::EntradaUsuario(vector<int> &vetor)
{
  vetor.clear(); // Zera o vetor
  int data;
  do
  {
    cout << "Entre com o dado (" << setw(3) << vetor.size()
         << ")(ctrl+d encerra entrada):";
    cin >> data;
    cin.get();
    if (cin.good())
      vetor.push_back(data);
  } while (cin.good());
  cin.clear(); // Reseta objeto cin para estado ok
  cout << endl;
}

// Preenchendo o vetor com uma sequência de valores padrões
void CTesteFuncoesGenericas::InicializaVetor(vector<int> &vetor, int n)
{
  vetor.clear();
  for (int i = 0; i < n; i++)
    vetor.push_back(i);
}

// Funcoes Auxiliares para uso posterior

// Declaração e definição da sobrecarga de <<
template <typename Tipo>
ostream &operator<<(ostream &os, const vector<Tipo> &v)
{
  for (int i = 0; i < v.size(); i++)
    os << setw(5) << setfill(' ') << v[i] << '\t';
  return os;
}

// Função de seleção da função a ser testada
bool CTesteFuncoesGenericas::Run()
{
  vector<string> funcoes = {
      "fill_n", "equal", "mismatch", "includes", "remove_copy_if", "replace_copy_if", "inplace_merge", "reverse_copy", "random_shuffle", "find_if", "find_if_off", "adjacent_difference", "search_n", "binary_search", "advance", "next_permutation", "reverse", "rotate", "generate", "for_each", "transform", "nth_element", "counf_if", "accumulate", "inner_product", "set_union", "set_intersection", "set_difference", "set_symmetric_difference", "make_heap", "plus", "minus", "times", "multiplies", "divides", "modulus", "negate", "equal_to", "not_equal_to", "greater", "less", "greater_equal", "less_equal", "logical_and", "logical_or", "logical_not", "bind2nd", "not1", "men_fun_ref", "find", "count", "copy_n", "iter_swap", "remove", "unique_copy", "partition", "sort", "is_sorted", "equal_range", "pop_heap", "min", "max_element", "none_of", "adjacent_find", "copy", "swap_ranges", "generate_n", "unique", "is_partitioned", "partition_point", "partial_sort_copy", "upper_bound", "push_heap", "is_heap_until", "min_element", "prev_permutation", " Mostra vetor"};

  cout << "============================================================\n"
       << "============= Qual função deseja testar ??? ================\n"
       << "============================================================\n";
  for (int i = 0; i < funcoes.size() / 4; i++)
  {
    //  funcoes.push_back(vs[i]);
    if (funcoes[i] != "")
      cout << "Uso de " << funcoes[i] << setw(27 - funcoes[i].size()) << setfill('.')
           << i
           << "\tUso de " << funcoes[i + 1 * funcoes.size() / 4] << setw(27 - funcoes[i + 1 * funcoes.size() / 4].size()) << setfill('.')
           << i + 1 * funcoes.size() / 4
           << "\tUso de " << funcoes[i + 2 * funcoes.size() / 4] << setw(27 - funcoes[i + 2 * funcoes.size() / 4].size()) << setfill('.')
           << i + 2 * funcoes.size() / 4
           << "\tUso de " << funcoes[i + 3 * funcoes.size() / 4] << setw(27 - funcoes[i + 3 * funcoes.size() / 4].size()) << setfill('.')
           << i + 3 * funcoes.size() / 4 << endl;
  }
  int selecao;
  cin >> selecao;
  cin.get();
  if (selecao >= funcoes.size())
    return 0;
  InicializaVetor(v);
  cout << setfill(' ') << "Vetor v = " << v << endl;

  if (funcoes[selecao] == "fill_n")
    Uso_de_fill_n();
  else if (funcoes[selecao] == "equal")
    Uso_de_equal();
  else if (funcoes[selecao] == "mismatch")
    Uso_de_mismatch();
  else if (funcoes[selecao] == "includes")
    Uso_de_includes();
  else if (funcoes[selecao] == "remove_copy_if")
    Uso_de_remove_copy_if();
  else if (funcoes[selecao] == "replace_copy_if")
    Uso_de_replace_copy_if();
  else if (funcoes[selecao] == "inplace_merge")
    Uso_de_inplace_merge();
  else if (funcoes[selecao] == "reverse_copy")
    Uso_de_reverse_copy();
  else if (funcoes[selecao] == "random_shuffle")
    Uso_de_random_shuffle();
  else if (funcoes[selecao] == "find_if")
    Uso_de_bind2nd();
  else if (funcoes[selecao] == "find_if_off")
    Uso_de_find_if_off();
  else if (funcoes[selecao] == "adjacent_difference")
    Uso_de_adjacent_difference();
  else if (funcoes[selecao] == "search_n")
    Uso_de_search_n();
  else if (funcoes[selecao] == "binary_search")
    Uso_de_binary_search();
  else if (funcoes[selecao] == "advance")
    Uso_de_advance();
  else if (funcoes[selecao] == "next_permutation")
    Uso_de_next_permutation();
  else if (funcoes[selecao] == "reverse")
    Uso_de_reverse();
  else if (funcoes[selecao] == "rotate")
    Uso_de_rotate();
  else if (funcoes[selecao] == "generate")
    Uso_de_generate();
  else if (funcoes[selecao] == "for_each")
    Uso_de_for_each();
  else if (funcoes[selecao] == "transform")
    Uso_de_transform();
  else if (funcoes[selecao] == "nth_element")
    Uso_de_nth_element();
  else if (funcoes[selecao] == "counf_if")
    Uso_de_counf_if();
  else if (funcoes[selecao] == "accumulate")
    Uso_de_accumulate();
  else if (funcoes[selecao] == "inner_product")
    Uso_de_inner_product();
  else if (funcoes[selecao] == "set_union")
    Uso_de_set_union();
  else if (funcoes[selecao] == "set_intersection")
    Uso_de_set_intersection();
  else if (funcoes[selecao] == "set_difference")
    Uso_de_set_difference();
  else if (funcoes[selecao] == "set_symmetric_difference")
    Uso_de_set_symmetric_difference();
  else if (funcoes[selecao] == "make_heap")
    Uso_de_make_heap();
  else if (funcoes[selecao] == "plus")
    Uso_de_plus();
  else if (funcoes[selecao] == "minus")
    Uso_de_minus();
  else if (funcoes[selecao] == "times")
    Uso_de_times();
  else if (funcoes[selecao] == "multiplies")
    Uso_de_multiplies();
  else if (funcoes[selecao] == "divides")
    Uso_de_divides();
  else if (funcoes[selecao] == "modulus")
    Uso_de_modulus();
  else if (funcoes[selecao] == "negate")
    Uso_de_negate();
  else if (funcoes[selecao] == "equal_to")
    Uso_de_equal_to();
  else if (funcoes[selecao] == "not_equal_to")
    Uso_de_not_equal_to();
  else if (funcoes[selecao] == "greater")
    Uso_de_greater();
  else if (funcoes[selecao] == "less")
    Uso_de_less();
  else if (funcoes[selecao] == "greater_equal")
    Uso_de_greater_equal();
  else if (funcoes[selecao] == "less_equal")
    Uso_de_less_equal();
  else if (funcoes[selecao] == "logical_and")
    Uso_de_logical_and();
  else if (funcoes[selecao] == "logical_or")
    Uso_de_logical_or();
  else if (funcoes[selecao] == "logical_not")
    Uso_de_logical_not();
  else if (funcoes[selecao] == "bind2nd")
    Uso_de_bind2nd();
  else if (funcoes[selecao] == "not1")
    Uso_de_bind2nd(); // usa not1
  else if (funcoes[selecao] == "men_fun_ref")
    Uso_de_men_fun_ref(funcoes);

  else if (funcoes[selecao] == "none_of")
    Uso_de_none_of();
  else if (funcoes[selecao] == "adjacent_find")
    Uso_de_adjacent_find();
  else if (funcoes[selecao] == "copy")
    Uso_de_copy();
  else if (funcoes[selecao] == "swap_ranges")
    Uso_de_swap_ranges();
  else if (funcoes[selecao] == "generate_n")
    Uso_de_generate_n();
  else if (funcoes[selecao] == "unique")
    Uso_de_unique();
  else if (funcoes[selecao] == "is_partitioned")
    Uso_de_is_partitioned();
  else if (funcoes[selecao] == "partition_point")
    Uso_de_partition_point();
  else if (funcoes[selecao] == "partial_sort_copy")
    Uso_de_partial_sort_copy();
  else if (funcoes[selecao] == "upper_bound")
    Uso_de_upper_bound();
  else if (funcoes[selecao] == "push_heap")
    Uso_de_push_heap();
  else if (funcoes[selecao] == "is_heap_until")
    Uso_de_is_heap_until();
  else if (funcoes[selecao] == "min_element")
    Uso_de_min_element();
  else if (funcoes[selecao] == "prev_permutation")
    Uso_de_prev_permutation();

  else if (funcoes[selecao] == "find")
    Uso_de_find();
  else if (funcoes[selecao] == "count")
    Uso_de_count();
  else if (funcoes[selecao] == "copy_n")
    Uso_de_copy_n();
  else if (funcoes[selecao] == "iter_swap")
    Uso_de_iter_swap();
  else if (funcoes[selecao] == "remove")
    Uso_de_remove();
  else if (funcoes[selecao] == "unique_copy")
    Uso_de_unique_copy();
  else if (funcoes[selecao] == "partition")
    Uso_de_partition();
  else if (funcoes[selecao] == "sort")
    Uso_de_sort();
  else if (funcoes[selecao] == "is_sorted")
    Uso_de_is_sorted();
  else if (funcoes[selecao] == "equal_range")
    Uso_de_equal_range();
  else if (funcoes[selecao] == "pop_heap")
    Uso_de_pop_heap();
  else if (funcoes[selecao] == "min")
    Uso_de_min();
  else if (funcoes[selecao] == "max_element")
    Uso_de_max_element();

  // Mostra o vetor
  else if (funcoes[selecao] == "Mostra vetor")
    cout << setfill(' ') << "Vetor  v= " << v << endl;
  // Sai do programa
  else if (funcoes[selecao] == "SAIR DO PROGRAMA")
    return 0;

  cout << "\a-->Pressione enter para continuar";
  cin.get();
  cin.clear();
  return 1; // se não escolheu sair retorna verdadeiro
}

// Preenchimento
void CTesteFuncoesGenericas::Uso_de_fill_n()
{
  fill_n(v.begin(), 3, 35);
  cout << setw(30) << "Vetor v apos fill_n(v.begin(), 3, 35); v= " << v << endl;
  fill_n(v.begin() + 3, 2, 36);
  cout << setw(30) << "Vetor v apos fill_n(v.begin() + 3, 2, 36); v= " << v << endl;
}
// Comparação
void CTesteFuncoesGenericas::Uso_de_equal()
{
  cout << setfill(' ') << "Vetor v2 = " << v2 << endl;
  if (equal(v.begin(), v.end(), v2.begin()))
    cout << "O conteúdo dos vetores é igual\n";
  else
    cout << "O conteúdo dos vetores são diferentes\n";
}
void CTesteFuncoesGenericas::Uso_de_mismatch()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// CTesteFuncoesGenericas::Uso_de_includes
void CTesteFuncoesGenericas::Uso_de_includes()
{
  v3 = v2 = v;
  v3.push_back(123);
  v2.push_back(333);
  cout << setw(30) << "Vetor  v2= " << v2 << endl;
  cout << setw(30) << "Vetor  v3= " << v3 << endl;
  //  cout.imbue(locale("pt_BR")); // opcional
  cout << setw(30) << "v  inclue v2 -> " << boolalpha << includes(v.begin(), v.end(), v2.begin(), v2.end()) << endl;
  cout << setw(30) << "v3 inclue v2 -> " << boolalpha << includes(v3.begin(), v3.end(), v2.begin(), v2.end()) << endl;
  cout << setw(30) << "v  inclue v3 -> " << boolalpha << includes(v.begin(), v.end(), v3.begin(), v3.end()) << endl;
  cout << setw(30) << "v2 inclue v3 -> " << boolalpha << includes(v2.begin(), v2.end(), v3.begin(), v3.end()) << endl;
  cout << setw(30) << "v2 inclue v  -> " << boolalpha << includes(v2.begin(), v2.end(), v.begin(), v.end()) << endl;
  cout << setw(30) << "v3 inclue v  -> " << boolalpha << includes(v3.begin(), v3.end(), v.begin(), v.end()) << endl;
}

// Remoção
void CTesteFuncoesGenericas::Uso_de_remove_copy_if()
{
  vector<int> v = {1, 2, 3, 4, 5, 6};
  vector<int> v2(6);
  remove_copy_if(v.begin(), v.end(), v2.begin(), [=](int i) { return i % 2; });
  cout << v2 << endl;
}

// Trocas
void CTesteFuncoesGenericas::Uso_de_replace_copy_if()
{
  cout << "Antes de replace_copy_if: v= " << v << endl;
  replace_copy_if(v.begin(), v.end(), v2.begin(), CNumeroImpar, 100);
  cout << "Depois de replace_copy_if (substitui valores impares por 100): \nv= " << v2 << endl;
  //cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl;

  replace_copy_if(v.begin(), v.end(), v2.begin(), CNumeroPar, 200);
  cout << "Depois de replace_copy_if (substitui valores pares por 200): \nv= " << v2 << endl;
}

// Misturar/mesclar/inverter
void CTesteFuncoesGenericas::Uso_de_inplace_merge()
{
  // cout << msg << "Exercício: Montar este exemplo. " << msg << endl
  EntradaUsuario(v);
  sort(v.begin(), v.end());

  EntradaUsuario(v2);
  sort(v2.begin(), v2.end());

  v3.resize(v.size() + v2.size());

  auto it = copy(v.begin(), v.end(), v3.begin());
  copy(v2.begin(), v2.end(), it);

  inplace_merge(v3.begin(), it, v3.end());

  cout << "Vetor v3=" << v3 << endl;
}

void CTesteFuncoesGenericas::Uso_de_reverse_copy()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// Embaralha os elementos do container
void CTesteFuncoesGenericas::Uso_de_random_shuffle()
{
  random_shuffle(v.begin(), v.end());
  cout << "Vetor  v após random_shufle= " << v << endl;
  sort(v.begin(), v.end());
  cout << "Vetor  v após sort= " << v << endl;
}

// Pesquisa
void CTesteFuncoesGenericas::Uso_de_find_if_off()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// CTesteFuncoesGenericas::Uso_de_adjacent_difference
void CTesteFuncoesGenericas::Uso_de_adjacent_difference()
{
  cout << "uso de adjacent_difference:";
  adjacent_difference(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void CTesteFuncoesGenericas::Uso_de_search_n()
{
  vector<int>::iterator itt;
  vector<int>::iterator itt2;
  itt = search_n(v.begin(), v.end(), 1, 3);

  cout << "A posicao do numero 3 no vetor v esta no indice " << (itt - v.begin()) << endl;
  v.push_back(4);
  v.push_back(4);
  cout << "Aumentando o vetor v com mais 2 elementos 4." << endl;
  cout << "Novo vetor v: " << v << endl;
  itt2 = search_n(v.begin(), v.end(), 3, 4);
  cout << "A posicao da terceira ocorrencia do numero 4 no vetor v esta no indice " << (itt2 - v.begin()) << endl;
}

// CTesteFuncoesGenericas::Uso_de_binary_search
// Retorna verdadeiro se o valor for encontrado
void CTesteFuncoesGenericas::Uso_de_binary_search()
{
  cout << "Valor " << 3 << (binary_search(v.begin(), v.end(), 3) ? " encontrado " : " não encontrado") << endl;
  cout << "Valor " << 22 << (binary_search(v.begin(), v.end(), 22) ? " encontrado " : " não encontrado") << endl;
}

// Avança o iterador
void CTesteFuncoesGenericas::Uso_de_advance()
{
  cout << "A partir da posição 0, devo avançar quantas casas (maximo="
       << v.size() << "):";
  int n;
  cin >> n;
  cin.get();
  vector<int>::iterator it = v.begin();
  advance(it, n);
  cout << "O iterador aponta agora para o elemento na posição "
       << (it - v.begin()) << " com o valor " << *it << endl;
}

// Ordenação
// Realiza permutação dos elementos do container
void CTesteFuncoesGenericas::Uso_de_next_permutation()
{
  for (int i = 0; i < v.size() * v.size(); i++)
  {
    next_permutation(v.begin(), v.end());
    cout << "Vetor  v após next_permutation= " << v << endl;
  }
}

void CTesteFuncoesGenericas::Uso_de_reverse()
{
  reverse(v.begin(), v.end());
  cout << "Vetor  v após reverse = " << v << endl;
}

// CTesteFuncoesGenericas::Uso_de_rotate
void CTesteFuncoesGenericas::Uso_de_rotate()
{
  rotate(v.begin(), v.begin() + v.size() / 2, v.end());
  cout << "Vetor  v após rotate(v.begin(),v.begin() + v.size()/2,"
       << " v.end())= " << v << endl;
}

// Transformação
// CTesteFuncoesGenericas::Uso_de_generate:a função chamada por generate não recebe parâmetro
// e retorna um elemento para o container no exemplo a seguir chama
// a função rand para preencher o container com números aleatórios
void CTesteFuncoesGenericas::Uso_de_generate()
{
  generate(v.begin(), v.end(), rand);
  cout << "Vetor de números aleatórios v= " << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_for_each()
{
  // cout << msg << "Exercício: Montar este exemplo. " << msg << endl;

  v2.clear();
  for_each(v.begin(), v.end(), [=](int i) { v2.push_back(i * 2); });
  cout << "Vetor v2 = 2*v" << v2 << endl;
}

void CTesteFuncoesGenericas::Uso_de_transform()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// Matemáticos
void CTesteFuncoesGenericas::Uso_de_nth_element()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

void CTesteFuncoesGenericas::Uso_de_counf_if()
{
  int impares = count_if(v.begin(), v.end(), CNumeroImpar);
  int pares = count_if(v.begin(), v.end(), CNumeroPar);
  cout << "A quantidade de numeros impares em v e: " << impares << endl;
  cout << "A quantidade de numeros pares em v e: " << pares << endl;
}

// Acumula valores no intervalo especificado
void CTesteFuncoesGenericas::Uso_de_accumulate()
{
  for (int i = 0; i < v.size(); i++)
    cout << "Valor acumulado até " << i << " = "
         << accumulate(v.begin(), v.begin(), 0) << endl; // + 1
}

void CTesteFuncoesGenericas::Uso_de_inner_product()
{
  cout << "ENTRE COM OS DADOS DO VETOR v\n";
  EntradaUsuario(v); // Entrada dos dados do vetor v
  cout << "\nENTRE COM OS DADOS DO VETOR v2\n";
  EntradaUsuario(v2); // Entrada dos dados do vetor v2
  cout << "\n"
       << "Vetor  v= " << v << endl;
  cout << "Vetor  v2= " << v2 << endl;
  cout << "ProdutoInterno v.v2 = "
       << inner_product(v.begin(), v.end(), v2.begin(), 0) << endl;
}

void CTesteFuncoesGenericas::Uso_de_set_union()
{
  v3 = v2 = v;
  v3.push_back(123);
  v2.push_back(333);
  cout << "Vetor  v2= " << v2 << endl;
  cout << "Vetor  v3= " << v3 << endl;
  cout << "União de v2 e v3 =";
  set_union(v3.begin(), v3.end(), v2.begin(), v2.end(),
            ostream_iterator<int>(cout, "\t"));
  cout << endl;
}

// CTesteFuncoesGenericas::Uso_de_set_intersection
void CTesteFuncoesGenericas::Uso_de_set_intersection()
{
  cout << "Interseção de v e v2 =";
  set_intersection(v.begin(), v.end(), v2.begin(), v2.end(),
                   ostream_iterator<int>(cout, "\t"));
  cout << endl;
}

// CTesteFuncoesGenericas::Uso_de_set_difference
void CTesteFuncoesGenericas::Uso_de_set_difference()
{
  cout << "Diferença de v2 e v3 (tem em v2 e não tem em v3)=";
  set_difference(v2.begin(), v2.end(), v3.begin(), v3.end(),
                 ostream_iterator<int>(cout, "\t"));
  cout << endl;
}

// CTesteFuncoesGenericas::Uso_de_set_symmetric_difference
void CTesteFuncoesGenericas::Uso_de_set_symmetric_difference()
{
  cout << "Diferença simétrica de v2 e v3 (tem em v2 e não tem em v3 ";
  cout << "ou tem em v3 e não tem em v2)=";
  set_symmetric_difference(v2.begin(), v2.end(), v3.begin(), v3.end(),
                           ostream_iterator<int>(cout, "\t"));
  cout << endl;
}

// Ordenação por pilha
void CTesteFuncoesGenericas::Uso_de_make_heap()
{
  // cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
  EntradaUsuario(v);
  make_heap(v.begin(), v.end());
  cout << "Vetor v como heap: " << v << endl;
  cout << "Maior elemento da heap (v.front): " << v.front() << endl;
}

// Funçães objeto
// Uso da função binária plus e de transform
void CTesteFuncoesGenericas::Uso_de_plus()
{
  cout << "Vetor  v= " << v << endl;
  cout << "Vetor  v2= " << v2 << endl;
  transform(v.begin(), v.end(), v2.begin(), v3.begin(), plus<int>());
  cout << "Vetor  v3 = v + v2 = " << v3 << endl;
}

// CTesteFuncoesGenericas::Uso_de_função binária da stl
// Uso da função binária minus e de transform
void CTesteFuncoesGenericas::Uso_de_minus()
{
  cout << "Vetor  v2= " << v2 << endl;
  transform(v.begin(), v.end(), v2.begin(), v3.begin(), minus<int>());
  cout << "Vetor  v3 = v - v2 = " << v3 << endl;
}

void CTesteFuncoesGenericas::Uso_de_times()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// Uso da função binária multiplies e de transform
void CTesteFuncoesGenericas::Uso_de_multiplies()
{
  cout << "Vetor  v= " << v << endl;
  cout << "Vetor  v2= " << v2 << endl;
  v.size() > v2.size() ? v3 = v : v3 = v2;
  transform(v.begin(), v.end(), v2.begin(), v3.begin(), multiplies<int>());
  cout << "Vetor  v3 = v * v2 = " << v3 << endl;
}

// Uso da função binária dividies e de transform
void CTesteFuncoesGenericas::Uso_de_divides()
{
  // Cada elemento do vetor é dividido pelo valor constante
  const float valor = 2;
  vector<float> vd(v.size());
  transform(v.begin(), v.end(), vd.begin(),
            bind2nd(divides<float>(), valor));
  cout << "Vetor de números float  vd= v/2.0= " << vd << endl;
}

// Cada elemento do vetor é dividido pelo valor constante,
// retorna o módulo
void CTesteFuncoesGenericas::Uso_de_modulus()
{
  const float valor = 2;
  vector<float> vd(v.size());
  transform(v.begin(), v.end(), vd.begin(),
            bind2nd(modulus<int>(), valor));
  cout << "Vetor de números vd= %( v / 2.0) = " << vd << endl;
}

// Cada elemento do vetor é invertido
void CTesteFuncoesGenericas::Uso_de_negate()
{
  transform(v.begin(), v.end(), v.begin(), negate<int>());
  cout << "Vetor  v após negate= " << v << endl;
}

// Cada elemento do vetor que for igual a 2 irá para o início do vetor
void CTesteFuncoesGenericas::Uso_de_equal_to()
{
  InicializaVetor(v);
  const float valor = 2;
  partition(v.begin(), v.end(), bind2nd(equal_to<int>(), valor));
  cout << "Rearranja o vetor de forma que todos os elementos ";
  cout << "iguais a 2 vão para o início" << endl;
  cout << "Vetor  v após equal_to<int>(2)= " << v << endl;
}

// Cada elemento do vetor que for diferente de 2
// irá para o início do vetor
void CTesteFuncoesGenericas::Uso_de_not_equal_to()
{
  InicializaVetor(v);
  const float valor = 2;
  partition(v.begin(), v.end(), bind2nd(not_equal_to<int>(), valor));
  cout << "Rearranja o vetor de forma que todos os elementos ";
  cout << "diferentes de 2 vão para o início" << endl;
  cout << "Vetor  v após not_equal_to<int>(2)= " << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_greater()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// Cada elemento do vetor menor que 2 irá para o início
void CTesteFuncoesGenericas::Uso_de_less()
{
  InicializaVetor(v);
  const float valor = 2;
  partition(v.begin(), v.end(), bind2nd(less<int>(), valor));
  cout << "Rearranja o vetor de forma que todos os elementos ";
  cout << "menores que 2 vão para o início" << endl;
  cout << "Vetor  v após less<int>(2)= " << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_greater_equal()
{
  vector<int> numeros{200, -30, 10, -40, 0, 5, 27, -99};
  int cx = count_if(numeros.begin(), numeros.end(), bind2nd(greater_equal<int>(), 0));
  cout << "Valores iniciais: " << numeros << endl;
  cout << "Existem " << cx << " positivos.\n";
}

void CTesteFuncoesGenericas::Uso_de_less_equal()
{
  EntradaUsuario(v);
  const int valor = 15;
  int resultadoComparaco = count_if(v.begin(), v.end(), bind2nd(less_equal<int>(), valor));
  cout << "No vetor v, " << resultadoComparaco << " elementos são menores que 15" << endl;
}

// Funçães lógicas
void CTesteFuncoesGenericas::Uso_de_logical_and()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

void CTesteFuncoesGenericas::Uso_de_logical_or()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

void CTesteFuncoesGenericas::Uso_de_logical_not()
{
  deque<bool> d1, d2(7);
  deque<bool>::iterator iter1, iter2;

  int i;
  for (i = 0; i < 7; i++)
  {
    d1.push_back((bool)((i % 2) != 0));
  }

  cout << boolalpha; // boolalpha I/O flag permitida

  cout << "Deque original:\n d1 = ( ";
  for (iter1 = d1.begin(); iter1 != d1.end(); iter1++)
    cout << *iter1 << " ";
  cout << ")" << endl;

  // Para inverter todos os elementos bool do deque,
  // usamos o objeto funcao logical_not
  transform(d1.begin(), d1.end(), d2.begin(), logical_not<bool>());
  cout << "O deque com seus valores opostos:\n d2 = ( ";
  for (iter2 = d2.begin(); iter2 != d2.end(); iter2++)
    cout << *iter2 << " ";
  cout << ")" << endl;
}

// Adaptadores
void CTesteFuncoesGenericas::Uso_de_bind2nd()
{
  vector<int>::iterator it = find_if(v.begin(), v.end(),
                                     not1(bind2nd(greater_equal<int>(), 20)));
  cout << "Valor maior que 20 localizado na posição " << (it - v.begin())
       << " com o valor " << *it;
}

void CTesteFuncoesGenericas::Uso_de_men_fun_ref(const vector<string> &s)
{
  {
    v.resize(s.size());
    transform(s.begin(), s.end(), v.begin(), mem_fun_ref(&string::size));
    cout << "Tamanho dos nome das funções: " << v << endl;
  }
}

/* Funcao none_of
Returns true if pred returns false for all the elements in the range [first, last]
or if the range is empty, and false otherwise. */

void CTesteFuncoesGenericas::Uso_de_none_of()
{
  vector<int> teste1{1, 3, 5, 7};
  vector<int> teste2{-2, -4, -6};

  bool resposta = none_of(v.begin(), v.end(), CNumeroImpar);
  cout << "Os elementos do vetor v (" << v << ") sao todos impares? " << resposta << endl;
  resposta = none_of(teste1.begin(), teste1.end(), Negativo);
  cout << "Os elementos do vetor teste1 (" << teste1 << ") sao todos negativos? " << resposta << endl;
  resposta = none_of(teste2.begin(), teste2.end(), Negativo);
  cout << "Os elementos do vetor teste2 (" << teste2 << ") sao todos negativos? " << resposta << endl;
}

/* Funcao: adjacent_find
Find equal adjacent elements in range
Searches the range [first,last) for the first occurrence of two consecutive elements that match,
and returns an iterator to the first of these two elements, or last if no such pair is found.
Two elements match if they compare equal using operator==
*/
void CTesteFuncoesGenericas::Uso_de_adjacent_find()
{
  v.push_back(5);
  v.push_back(5);
  v.push_back(6);
  v.push_back(6);
  vector<int>::iterator itt = adjacent_find(v.begin(), v.end());

  cout << "Novos valores do vetor: " << v << "\n. Valor do primeiro elemento que se repete: " << *itt << endl;
  cout << "A posicao do primeiro elemento que se repete: " << (itt - v.begin()) << endl;
}

/* Funcao: copy
Copy range of elements
Copies the elements in the range [first,last) into the range beginning at result.
The function returns an iterator to the end of the destination range (which points to the element following
the last element copied). */
void CTesteFuncoesGenericas::Uso_de_copy()
{
  vector<int> copia(5, 10);
  cout << "Valores do vetor 1: " << v << endl;
  cout << "Valores do vetor 2: " << copia << endl;

  copy(v.begin(), v.begin() + 3, copia.begin());
  cout << "3 primeiros valores do vetor 1 copiado para o vetor 2: " << copia << endl;

  copy(v.begin(), v.end(), copia.begin());
  cout << "Copia completa do vetor 1 para o vetor 2: " << copia << endl;
}

/*Funcao: swap_ranges
std::swap is used for swapping of elements between two containers.
One of its variation is std::swap_ranges, which as the name suggests is used for swapping the elements within a range.
It simply exchanges the values of each of the elements in the range [first1, last1) with those of their respective elements
in the range beginning at first2. If we look at its internal working, we will find that this function itself uses std::swap(). */

void CTesteFuncoesGenericas::Uso_de_swap_ranges()
{
  vector<int> teste(5, 10);
  cout << "Valor do vetor 1 inicial :" << v << endl;
  cout << "Valor do vetor 2 inicial :" << teste << endl;

  swap_ranges(v.begin() + 1, v.end() - 1, teste.begin());
  cout << "Valor do vetor 1 trocado a partir da posicao 1 ate a posicao 3 :" << v << endl;
  cout << "Valor do vetor 2 trocado a partir do comeco:" << teste << endl;
}

/*Funcao: generate_n
Generate values for sequence with function
Assigns the value returned by successive calls to gen to the first n elements of the sequence pointed by first. */

int atual = 0;
int Dobro() { return (atual++) * 2; }

void CTesteFuncoesGenericas::Uso_de_generate_n()
{

  vector<int> teste(10, 0);
  generate_n(teste.begin(), 10, Dobro);

  cout << "Os valores do vetor criado sao: " << teste << endl;
}

/*Funcao: unique
std::unique is used to remove duplicates of any element present consecutively in a range[first, last).
It performs this task for all the sub-groups present in the range having the same element present consecutively.
*/
void CTesteFuncoesGenericas::Uso_de_unique()
{
  vector<int>::iterator itt1, itt2;
  cout << "Valores do vetor 1 antes: " << v << endl;
  itt1 = unique(v.begin(), v.end());
  cout << "Valores do vetor 1 depois: " << v << endl;
  cout << "Valores do vetor iterador 1: " << *itt1 << endl;

  vector<int> v1{0, 1, 2, 2, 3, 4, 2, 4, 4, 2, 5, 6, 10};
  cout << "Valores do vetor 2 antes: " << v1 << endl;
  itt2 = unique(v1.begin(), v1.end());
  cout << "Valores do vetor 2 depois: " << v1 << endl;
  cout << "Valores do vetor iterador 2: " << *itt2 << endl;
  cout << "Posicao do vetor iterador 2: " << (itt2 - v1.begin()) << endl;

  // v1.resize(std::distance(v1.begin(), itt2));
}

/*Funcao: is_partitioned
std::is_partitioned is used for finding whether the range[first, last) is partitioned or not.
A range is said to be partitioned with respect to a condition if all the elements for which the condition
evaluates to true precede those for which it is false. */

void CTesteFuncoesGenericas::Uso_de_is_partitioned()
{
  vector<int> teste1{1, 3, -5, 7};
  vector<int> teste2{-1, 3, 5, 7};
  bool resposta;

  cout << "Condicao avaliada: os numeros sao negativos.";
  resposta = is_partitioned(teste1.begin(), teste1.end(), Negativo);
  cout << "Os dados do vetor " << teste1 << " estao parcionados? " << resposta << endl;
  resposta = is_partitioned(teste2.begin(), teste2.end(), Negativo);
  cout << "Os dados do vetor " << teste2 << " estao parcionados? " << resposta << endl;
}

/* Funcao: partition_point
This function returns an iterator pointing to the partition point of container i.e.
the first element in the partitioned range [beg,end) for which condition is not true.
The container should already be partitioned for this function to work. */

void CTesteFuncoesGenericas::Uso_de_partition_point()
{
  vector<int> teste2{-1, 3, 5, 7};
  cout << "Os dados do vetor parcionados: " << teste2 << endl;
  vector<int>::iterator itt = partition_point(teste2.begin(), teste2.end(), Negativo);
  cout << "O primeiro elemento a tornar verdadeiro o parcionamento e " << *itt << endl;
  cout << "A posicao no vetor e " << (itt - teste2.begin()) << endl;
}

/*Funcao: partial_sort_copy
std::partial_sort is used for sorting the range within the entire container.
So, if we want to keep the original container intact and just copy the sorted sub-part of the container into
another one, then for that purpose, we can use std::partial_sort_copy.*/

void CTesteFuncoesGenericas::Uso_de_partial_sort_copy()
{
  vector<int> v1{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  vector<int> resposta(10);

  cout << "Vetor inicial: " << v1 << endl;
  partial_sort_copy(v1.begin(), v1.end() - 2, resposta.begin(), resposta.end());
  cout << "Vetor final: " << resposta << endl;

  vector<string> txt1{"biscoito", "agua", "cafe"};
  vector<string> txt2(3);

  cout << "Vetor inicial: " << txt1 << endl;
  partial_sort_copy(txt1.begin(), txt1.end(), txt2.begin(), txt2.end());
  cout << "Vetor final: " << txt2 << endl;
}

/* Funcao: upper_bound
Return iterator to upper bound
Returns an iterator pointing to the first element in the range [first,last) which compares greater than value indicated. */

void CTesteFuncoesGenericas::Uso_de_upper_bound()
{
  vector<int>::iterator upper;
  upper = upper_bound(v.begin(), v.end(), 2);
  cout << "Os valores do vetor sao: " << v << endl;
  cout << "O primeiro valor alem do escolhido (2) e " << *upper << endl;
}

/* Funcao push_heap
Heap data structure can be implemented in a range using STL which allows faster input into heap and retrieval of
a number always results in the largest number i.e. largest number of the remaining numbers is popped out each time.
This function is used to insert elements into heap. The size of the heap is increased by 1.
New element is placed appropriately in the heap. */
void CTesteFuncoesGenericas::Uso_de_push_heap()
{
  vector<int> v1{10, 20, 50, 40, 30};
  cout << "Os valores do vetor sao: " << v1 << endl;
  make_heap(v1.begin(), v1.end());
  //cout << "Os novos valores do vetor sao, apos criar o heap: " << v1 << endl;
  cout << "O valor maximo do heap criado a partir do vetor e :" << v1.front() << endl;
  //cout << "Os valores finais do vetor sao: " << v1 << endl;

  v1.push_back(55);
  cout << "Os valores do vetor sao: " << v1 << endl;
  push_heap(v1.begin(), v1.end());
  //cout << "O novo valor maximo do heap e :" << v1.front() << endl;
  cout << "O valor maximo do heap criado a partir do vetor e :" << v1.front() << endl;
  //cout << "Os valores finais do vetor sao: " << v1 << endl;
}

/* Funcao is_heap_until
Returns and iterator to the first element of the range [first, last) which is not in a valid position if the range is
considered a heap */

void CTesteFuncoesGenericas::Uso_de_is_heap_until()
{
  vector<int> numeros{9, 1, 4, 5, 7, 8, 2, 6, 3, 0};

  auto primeiro = is_heap_until(numeros.begin(), numeros.end());

  cout << "O primeiro valor a nao ser entendido como heap e " << *primeiro << " , e esta na posicao " << (primeiro - numeros.begin()) << endl;

  sort(numeros.begin(), numeros.end());
  reverse(numeros.begin(), numeros.end());

  auto ultimo = is_heap_until(numeros.begin(), numeros.end());
  cout << "Os " << (ultimo - numeros.begin()) << " primeiros elementos de um heap valido sao: ";

  for (auto itt = numeros.begin(); itt != numeros.end(); ++itt)
    cout << ' ' << *itt;
  cout << "\n";
}

/* Funcao min_element
 std::min_element is defined inside the header file <algorithm> and it returns an iterator pointing to the
 element with the smallest value in the range [first, last). */

void CTesteFuncoesGenericas::Uso_de_min_element()
{
  vector<int>::iterator upper;
  vector<int>::iterator itt = min_element(v.begin() + 1, v.end());
  cout << "O valor do menor elemento no range especificado e : " << *itt << endl;
}

/* Funcao prev_permutation
It is used to rearrange the elements in the range [first, last) into the next lexicographically greater permutation. */

void CTesteFuncoesGenericas::Uso_de_prev_permutation()
{

  string s = "abc";
  sort(s.begin(), s.end(), greater<char>());
  do
  {
    cout << s << " ";
  } while (prev_permutation(s.begin(), s.end()));
  cout << "\n";
}

void CTesteFuncoesGenericas::Uso_de_find()
{
  EntradaUsuario(v);
  cout << "Digite o valor a ser buscado: ";
  int valorBuscado;
  cin >> valorBuscado;
  auto it = find(v.begin(), v.end(), valorBuscado);
  if (it != v.end())
    cout << "O valor foi encontrado na posição: " << it - v.begin() << endl;
  else
    cout << "O valor não foi encontrado no vetor." << endl;
  cin.get();
}

void CTesteFuncoesGenericas::Uso_de_count()
{
  EntradaUsuario(v);
  int valorRepetido = 5;
  auto it = count(v.begin(), v.end(), valorRepetido);
  cout << "O valor " << valorRepetido << " aparece no vetor " << it << " vezes" << endl;
}

void CTesteFuncoesGenericas::Uso_de_copy_n()
{
  int n = 3;
  // std::cout << v << std::endl;
  InicializaVetor(v);
  v2.resize(n);
  copy_n(v.begin(), n, v2.end());
  cout << "Os primeiros " << n << " elementos do vetor v:" << v2 << endl;
}

void CTesteFuncoesGenericas::Uso_de_iter_swap()
{
  InicializaVetor(v, 10);
  InicializaVetor(v2, 5);
  iter_swap(v.begin(), v2.begin() + 3);

  cout << "Vetor v:" << v << endl;
  cout << "Vetor v2:" << v2 << endl;
}

void CTesteFuncoesGenericas::Uso_de_remove()
{
  EntradaUsuario(v);
  remove(v.begin(), v.end(), 5);
  cout << "Vetor v sem os valores iguais a 5:" << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_unique_copy()
{
  EntradaUsuario(v);
  v2.resize(v.size());
  auto it = unique_copy(v.begin(), v.end(), v2.begin());
  v2.resize(distance(v2.begin(), it));
  cout << "Vetor v sem repetições:" << v2 << endl;
}

void CTesteFuncoesGenericas::Uso_de_partition()
{
  EntradaUsuario(v);
  v2.clear();
  v2.resize(v.size());
  int multiplo = 5;
  auto it = partition(v.begin(), v.end(), [=](int i) { return (i % multiplo); });
  copy(it, v.end(), v2.begin());
  std::cout << "Valores de v multiplos de " << multiplo << ":" << v2 << std::endl;
}

void CTesteFuncoesGenericas::Uso_de_sort()
{
  EntradaUsuario(v);
  sort(v.begin(), v.end());

  cout << "Vetor v ordenado:" << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_is_sorted()
{
  EntradaUsuario(v);
  cout << "Vetor v está ordenado? " << is_sorted(v.begin(), v.end()) << endl;
  sort(v.begin(), v.end());
  cout << "Vetor v está ordenado? " << is_sorted(v.begin(), v.end()) << endl;

  cout << "Vetor v ordenado:" << v << endl;
}

void CTesteFuncoesGenericas::Uso_de_equal_range()
{
  EntradaUsuario(v);
  sort(v.begin(), v.end());
  int valor = 20;
  auto limites = equal_range(v.begin(), v.end(), valor);
  cout << "Posicao do limite inferior: " << limites.first - v.begin() << endl;
  cout << "Posicao do limite superior: " << limites.second - v.begin() << endl;
}

void CTesteFuncoesGenericas::Uso_de_pop_heap()
{
  EntradaUsuario(v);
  make_heap(v.begin(), v.end());
  cout << "Valor máximo no heap: " << v.front() << endl;
  pop_heap(v.begin(), v.end());
  cout << "Valor máximo no heap depois do pop: " << v.front() << endl;
}

void CTesteFuncoesGenericas::Uso_de_min()
{
  cout << "Menor valor entre 2 e 5: " << min(2, 5) << endl;
}

void CTesteFuncoesGenericas::Uso_de_max_element()
{
  EntradaUsuario(v);
  cout << "Maior elemento em v: " << *max_element(v.begin(), v.end()) << endl;
}

int main()
{
  CTesteFuncoesGenericas obj;
  while (obj.Run())
    ;
  return 0;
}
