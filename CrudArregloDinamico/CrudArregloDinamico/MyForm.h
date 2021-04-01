#pragma once
#include "ArregloEmpleado.h"
#include "string.h"

namespace CrudArregloDinamico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			obj = new ArregloEmpleado();
			InitializeComponent();
			CargarListado();
			CargarCategorias();

		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Apellido;
	private: System::Windows::Forms::Label^ Año;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtApellido;
	private: System::Windows::Forms::TextBox^ txtAnioIng;
	private: System::Windows::Forms::TextBox^ txtSueldo;




	private: System::Windows::Forms::ComboBox^ cbCategoria;

	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::DataGridView^ dataGrid;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Codigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombres;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	protected:

	private:
		ArregloEmpleado* obj;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnCancelar;
		   System::ComponentModel::Container^ components;

		void CargarCategorias() {
			cbCategoria->Items->Clear();
			cbCategoria->Items->Add("A");
			cbCategoria->Items->Add("B");
			cbCategoria->Items->Add("C");
			cbCategoria->Items->Add("D");
		}

		String^ toString(string valor) {
			return  gcnew String(valor.c_str());
		}
		string toString(String^ valor) {
			string cadena = "";

			for (int i = 0; i < valor->Length;i++) {
				cadena = cadena + (char)valor[i];
			}

			return cadena;
		}

		void LimpiarCasillas() {
			txtNombre->Text = "";
			txtApellido->Text = "";
			txtAnioIng->Text = "";
			txtSueldo->Text = "";
		}

		void CargarListado() {
			dataGrid->Rows->Clear();
			for (int i = 0; i < obj->getNum();i++) {
				Empleado* e = obj->Obtener(i);
				
				dataGrid->Rows->Add(e->getCodigo() , toString(e->getNombre()), toString(e->getApellido()) ,
					toString(e->getCategoria()),e->getAnioIngreso() , e->getSueldo());
			}
		}

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Apellido = (gcnew System::Windows::Forms::Label());
			this->Año = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtApellido = (gcnew System::Windows::Forms::TextBox());
			this->txtAnioIng = (gcnew System::Windows::Forms::TextBox());
			this->txtSueldo = (gcnew System::Windows::Forms::TextBox());
			this->cbCategoria = (gcnew System::Windows::Forms::ComboBox());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Codigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nombres = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// Apellido
			// 
			this->Apellido->AutoSize = true;
			this->Apellido->Location = System::Drawing::Point(35, 74);
			this->Apellido->Name = L"Apellido";
			this->Apellido->Size = System::Drawing::Size(44, 13);
			this->Apellido->TabIndex = 1;
			this->Apellido->Text = L"Apellido";
			// 
			// Año
			// 
			this->Año->AutoSize = true;
			this->Año->Location = System::Drawing::Point(254, 34);
			this->Año->Name = L"Año";
			this->Año->Size = System::Drawing::Size(64, 13);
			this->Año->TabIndex = 2;
			this->Año->Text = L"Año Ingreso";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(254, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Sueldo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Categoria";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(96, 31);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(125, 20);
			this->txtNombre->TabIndex = 5;
			// 
			// txtApellido
			// 
			this->txtApellido->Location = System::Drawing::Point(96, 71);
			this->txtApellido->Name = L"txtApellido";
			this->txtApellido->Size = System::Drawing::Size(125, 20);
			this->txtApellido->TabIndex = 6;
			// 
			// txtAnioIng
			// 
			this->txtAnioIng->Location = System::Drawing::Point(324, 31);
			this->txtAnioIng->Name = L"txtAnioIng";
			this->txtAnioIng->Size = System::Drawing::Size(125, 20);
			this->txtAnioIng->TabIndex = 7;
			// 
			// txtSueldo
			// 
			this->txtSueldo->Location = System::Drawing::Point(324, 71);
			this->txtSueldo->Name = L"txtSueldo";
			this->txtSueldo->Size = System::Drawing::Size(125, 20);
			this->txtSueldo->TabIndex = 8;
			// 
			// cbCategoria
			// 
			this->cbCategoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbCategoria->FormattingEnabled = true;
			this->cbCategoria->Location = System::Drawing::Point(96, 111);
			this->cbCategoria->Name = L"cbCategoria";
			this->cbCategoria->Size = System::Drawing::Size(125, 21);
			this->cbCategoria->TabIndex = 9;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(257, 111);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 10;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &MyForm::btnAgregar_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AllowUserToAddRows = false;
			this->dataGrid->AllowUserToDeleteRows = false;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Codigo, this->Nombres,
					this->Column1, this->Column2, this->Column3, this->Column4
			});
			this->dataGrid->Location = System::Drawing::Point(30, 159);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->ReadOnly = true;
			this->dataGrid->Size = System::Drawing::Size(665, 201);
			this->dataGrid->TabIndex = 11;
			this->dataGrid->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGrid_CellClick);
			// 
			// Codigo
			// 
			this->Codigo->HeaderText = L"Codigo";
			this->Codigo->Name = L"Codigo";
			this->Codigo->ReadOnly = true;
			// 
			// Nombres
			// 
			this->Nombres->HeaderText = L"Nombres";
			this->Nombres->Name = L"Nombres";
			this->Nombres->ReadOnly = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Apellido";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Categoria";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Año Ingreso";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Sueldo";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// btnModificar
			// 
			this->btnModificar->Enabled = false;
			this->btnModificar->Location = System::Drawing::Point(339, 111);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(75, 23);
			this->btnModificar->TabIndex = 12;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &MyForm::btnModificar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Enabled = false;
			this->btnEliminar->Location = System::Drawing::Point(420, 111);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 13;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &MyForm::btnEliminar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(511, 111);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(75, 23);
			this->btnCancelar->TabIndex = 14;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &MyForm::btnCancelar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 408);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->cbCategoria);
			this->Controls->Add(this->txtSueldo);
			this->Controls->Add(this->txtAnioIng);
			this->Controls->Add(this->txtApellido);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Año);
			this->Controls->Add(this->Apellido);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Crud Empleados";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
	
		string nombre = toString(txtNombre->Text);
		string apellido = toString(txtApellido->Text);
		int anioIng = Convert::ToInt32(txtAnioIng->Text);
		double sueldo = Convert::ToDouble(txtSueldo->Text);
		string categoria = toString(Convert::ToString(cbCategoria->SelectedItem));
	
		// Empleado* e = new Empleado(nombre , apellido , categoria, anioIng, sueldo);
		obj->Agregar(new Empleado(nombre, apellido, categoria, anioIng, sueldo));
		CargarListado();
		LimpiarCasillas();
	}
private: System::Void dataGrid_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int posicion = e->RowIndex;
	int indice = dataGrid->CurrentRow->Index;

	if (posicion !=-1) {
		txtNombre->Text = dataGrid->Rows[posicion]->Cells[1]->Value->ToString();
		txtApellido->Text = dataGrid->Rows[posicion]->Cells[2]->Value->ToString();
		txtAnioIng->Text = dataGrid->Rows[posicion]->Cells[4]->Value->ToString();
		txtSueldo->Text = dataGrid->Rows[posicion]->Cells[5]->Value->ToString();
		cbCategoria->SelectedItem = dataGrid->Rows[posicion]->Cells[3]->Value->ToString();
		
		btnEliminar->Enabled = true;
		btnModificar->Enabled = true;
		btnAgregar->Enabled = false;
	}
	
	/*
	PRIMERA FORMA
	Empleado *emp = obj->Obtener(posicion);
	txtNombre->Text = toString(emp->getNombre());
	*/
}
private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
	int indice = dataGrid->CurrentRow->Index;
	string nombre = toString(txtNombre->Text);
	string apellido = toString(txtApellido->Text);
	int anioIng = Convert::ToInt32(txtAnioIng->Text);
	double sueldo = Convert::ToDouble(txtSueldo->Text);
	string categoria = toString(Convert::ToString(cbCategoria->SelectedItem));

    obj->Actualizar(new Empleado(nombre, apellido, categoria, anioIng, sueldo), indice);
	CargarListado();
	LimpiarCasillas();
	btnModificar->Enabled = false;
	btnEliminar->Enabled = false;
	btnAgregar->Enabled = true;
}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	int indice = dataGrid->CurrentRow->Index;
	if (indice !=-1) {

		if (MessageBox::Show("¿Esta seguro que desea eliminar?",
			"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			obj->Eliminar(indice);
			CargarListado();
			LimpiarCasillas();
			btnModificar->Enabled = false;
			btnEliminar->Enabled = false;
			btnAgregar->Enabled = true;
		}
	}
}
private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
	LimpiarCasillas();
	btnModificar->Enabled = false;
	btnEliminar->Enabled = false;
	btnAgregar->Enabled = true;

	dataGrid->ClearSelection();
}
};
}
