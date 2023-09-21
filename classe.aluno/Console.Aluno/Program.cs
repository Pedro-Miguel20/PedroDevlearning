using System;
using System.Data;
using System.Drawing;
using System.Net.Http.Json;
using System.Text.RegularExpressions;

Console.WriteLine("Aluno Sistema");
Console.WriteLine("-----------------------------");

var aluno = new Aluno();
aluno.Nome = "Pedro Miguel Aguiar de Arruda";
aluno.DataNascimento = DateTime.Parse("26/01/2002"); 
aluno.SetCpf("03529019267");
aluno.Telefone=992581986;
aluno.Cep = "76824088";
aluno.Email = "pm987162@gmail.com";
await aluno.BuscaCep();

Console.WriteLine($"Aluno: {aluno.Nome}");
Console.WriteLine($"Primeiro Nome: {aluno.FirstName}");
Console.WriteLine($"Ultimo Nome: {aluno.LastName}");
Console.WriteLine($"Nascimento:   {aluno.DataNascimento?.ToString("dd/MM/yyyy")}");
Console.WriteLine($"Idade: {aluno.idade}");
if (aluno.IsInvalid != false)
{
    Console.WriteLine(aluno.GetCpf());
}
else
{
    Console.WriteLine("invalid");
}
Console.WriteLine($"Email: {aluno.Email}");
Console.WriteLine($"Telefone: {aluno.Telefone}");
Console.WriteLine($"Cep: {aluno.Cep}");
Console.WriteLine($"Logradouro: {aluno.Logradouro}");
Console.WriteLine($"cidade: {aluno.Localidade}");
Console.WriteLine($"UF: {aluno.Uf}");
	

public class Aluno
{
	public bool IsInvalid;
    public string Nome { get; set; }
    public DateTime? DataNascimento { get; set; }

    public int? idade => DataNascimento.GetIdade();
    public string? Email {  get; set; }
	public string PrimeiroNome { get; set; }
	public string UltimoNome { get; set; }
	public string FirstName => Nome.GetPrimeiroNome();
	public string LastName => Nome.GetUltimoNome();

    public string? Cep { get; set; }
    public string? Logradouro { get; set; }
    public string? Complemento { get; set; }
    public string? Numero { get; set; }
    public string? Bairro { get; set; }
    public string? Localidade { get; set; }
    public string? Uf { get; set; }

	public async Task BuscaCep()
	{
		var cepDto = await ApiHelper.getCep(Cep);
		Logradouro = cepDto.Logradouro;
		Localidade = cepDto.Localidade;
		Bairro = cepDto.Bairro;
        Uf = cepDto.Uf;
	}



    private string cpf;
	public string Cpf
	{ get { return cpf; } set {  cpf = value; } }
    public string GetCpf()
	{
		return $"CPF: {cpf.Substring(0, 3)}.{cpf.Substring(3, 3)}.{cpf.Substring(6, 3)}-{cpf.Substring(9, 2)}";
	}
	
	public bool SetCpf(string valor)
	{
		if (valor.Length == 11)
		{
		    cpf = valor;
			int soma = 0, resto = 0;
			for (int i = 0; i < 9; i++)
			{
				int n = Convert.ToInt32(cpf.Substring(i, 1));
				soma += n * (10 - i);
			}

			resto = (soma % 11);
			resto = (resto <= 2 ? 0 : 11 - resto);
			if (resto != Convert.ToInt32(cpf.Substring(9, 1)))
			{
                return IsInvalid = false;
            }

			soma = 0;
			for (int i = 0; i < 10; i++)
			{
				int n = Convert.ToInt32(cpf.Substring(i, 1));
				soma += n * (11 - i);
			}

			resto = (soma % 11);
			resto = (resto <= 2 ? 0 : 11 - resto);
			if (resto != Convert.ToInt32(cpf.Substring(10, 1)))
			{
                return IsInvalid = false;
            }
			return IsInvalid = true;
		}
		else
		{
            return IsInvalid = false;
        }
    }

    //private int cep;
    //private int numero;
    //private string endereco;
    //private string complemento;
    private int telefone;
	public int Telefone{ get; set; }
}
public static class StringHelper
{
	public static string GetPrimeiroNome(this string nome)
    {
        var nomes = nome.Split(' ');
        return nomes[0];
	}
	public static string GetUltimoNome(this string nome)
    {
        var nomes = nome.Split(' ');
        return nomes[nomes.Length - 1];
    }
}

public static class StringExtension
{
    public static string GetNumeros(this string texto)
    {
        return new string(texto.Where(char.IsDigit).ToArray());
    }

    public static bool VerificaEmail(string? email)
    {
        if (email == null) return false;
        Regex regex = new Regex(@"^([\w\.\-]+)@([\w\-]+)((\.(\w){2,3})+)$");
        Match match = regex.Match(email);
        if (!match.Success) return false;
        return true;
    }

}

public static class DateTimeExtension
{
    public static int? GetIdade(this DateTime? dataNascimento)
    {
        if (dataNascimento == null) return null;
        int idade = DateTime.Now.Year - dataNascimento.Value.Year;
        if (DateTime.Now.DayOfYear < dataNascimento.Value.DayOfYear)
            idade--;
        return idade;
    }
}

public class CepDto
{
    public string? Cep { get; set; }
    public string? Logradouro { get; set; }
    public string? Complemento { get; set; }
    public string? Bairro { get; set; }
    public string? Localidade { get; set; }
    public string? Uf { get; set; }
    public string? Ibge { get; set; }
    public string? Gia { get; set; }
    public string? Ddd { get; set; }
    public string? Siafi { get; set; }
}


public static class ApiHelper
{
	private static HttpClient http = new();

	public static async Task<CepDto?> getCep(string cep)
	{
        cep = cep.GetNumeros();
        var cepDto = await http.GetFromJsonAsync<CepDto>($"https://viacep.com.br/ws/{cep}/json");
        return cepDto;
    }
}