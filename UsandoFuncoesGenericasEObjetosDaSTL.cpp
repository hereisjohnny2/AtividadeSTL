#include <iostream>   // Entrada e sa�da de dados
#include <iomanip>    // Manipuladores
#include <string>     // Strings de C++
#include <vector>     // Classe de vetores
#include <algorithm>  // Classe para algoritmos gen�ricos
#include <memory>     // destroe e construct
#include <cstdlib>    // Função rand
#include <numeric>    // Função inner_product
#include <functional> // Função
#include <iterator>   // Iteradores

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

  // M�todos p�blicos
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
  void Uso_de_find();
  void Uso_de_count();
  void Uso_de_copy_n();
}; // fim da classe

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
      "fill_n", "equal", "mismatch", "includes", "remove_copy_if", "replace_copy_if", "inplace_merge", "reverse_copy", "random_shuffle", "find_if", "find_if_off", "adjacent_difference", "search_n", "binary_search", "advance", "next_permutation", "reverse", "rotate", "generate", "for_each", "transform", "nth_element", "counf_if", "accumulate", "inner_product", "set_union", "set_intersection", "set_difference", "set_symmetric_difference", "make_heap", "plus", "minus", "times", "multiplies", "divides", "modulus", "negate", "equal_to", "not_equal_to", "greater", "less", "greater_equal", "less_equal", "logical_and", "logical_or", "logical_not", "bind2nd", "not1", "men_fun_ref", "find", "count", "copy_n", " Mostra vetor"};

  cout << "============================================================\n"
       << "============= Qual função deseja testar ??? ================\n"
       << "============================================================\n";
  for (int i = 0; i < funcoes.size() / 2; i++)
  {
    //  funcoes.push_back(vs[i]);
    if (funcoes[i] != "")
      cout << "Uso de " << funcoes[i] << setw(30 - funcoes[i].size()) << setfill('.')
           << i
           << "\tUso de " << funcoes[i + funcoes.size() / 2] << setw(30 - funcoes[i + funcoes.size() / 2].size()) << setfill('.')
           << i + funcoes.size() / 2 << endl;
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
  else if (funcoes[selecao] == "find")
    Uso_de_find();
  else if (funcoes[selecao] == "count")
    Uso_de_count();
  else if (funcoes[selecao] == "copy_n")
    Uso_de_copy_n();

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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}
// Comparação
void CTesteFuncoesGenericas::Uso_de_equal()
{
  // cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

// Trocas
void CTesteFuncoesGenericas::Uso_de_replace_copy_if()
{
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
}

void CTesteFuncoesGenericas::Uso_de_less_equal()
{
  // cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
  EntradaUsuario(v);
  const int valor = 15;
  int resultadoComparaco = count_if(v.begin(), v.end(), bind2nd(less_equal<int>(), valor));
  cout << "No vetor v, " << resultadoComparaco << " elementos são menores que 15" << endl;
}

// Funçães l�gicas
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
  cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
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
    // cout << msg << "Exercício: Montar este exemplo. " << msg << endl;
    vector<string> s = {"casa", "bola", "carro", "jogo"};
    transform(s.begin(), s.end(), v.begin(), mem_fun_ref(&string::size));
    cout << "Tamanho das palavras em s: " << v << endl;
  }
  /*
  vector<int>::const_iterator it = find_if(s.begin(),s.end(),men_fun_ref(&string::empty));
  cout << "String vazia na posição:"  << it - s.begin() << endl;
  */
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
  v2.resize(n);
  copy_n(v.begin(), n, v2.end());
  cout << "Os primeiros " << n << " elementos do vetor v:" << v2 << endl;
}

int main()
{
  CTesteFuncoesGenericas obj;
  while (obj.Run())
    ;
  return 0;
}
