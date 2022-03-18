#include <iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;
class date            //  to handle date enteries
{
	int day = 0, month = 0, year = 0;
public:
	date()
	{}
	date(int a, int b, int c)
	{
		day = a; month = b; year = c;
	}
	int getday() { return day; }
	int getmonth() { return month; }
	int getyear() { return year; }
	date operator+(const date& a)  // to find the date for next appointment
	{
		date temp;
		temp.day = day + a.day;
		temp.month = month + a.month;
		temp.year = year + a.year;
		if (temp.day > 30)                     // loop to correct the date if it exceeds 30
		{
			int x;
			x = temp.day - 30;
			temp.day = x;
			if (temp.month <= 11)
				{ temp.month += 1;}
			else
			{ temp.year += 1;}
			return temp;
		}
		else
		{return temp;}
	}
	
}today(20,5,2021);       // instance of a class is created
class PATIENT
{
private:
	friend class date ;
	string name;
	const int ID;
	char gender;
public:
	PATIENT(int id, string name, char gender) : ID(id)     //  taking patient info using parametrized constructor
	{
		cout << "Today's date is: " << today.getday() << "/" << today.getmonth() << "/" << today.getyear() << endl << endl;
		this->name = name;
		this->gender = gender;
	}
	void StoreInfo()       //  copying patient info in a text file
	{
		ofstream fout;
		fout.open("Patient.txt", ios::app);
		fout << "Patient's Name:" << name << "\n";
		fout << "Patient ID:  " << ID << "\n";
		fout << "Patient's gender: " << gender << "\n";
		fout << "Date of admission: " << today.getday() << "/" << today.getmonth() << "/" << today.getyear() << "\n";
		fout.close();
	}
};
class CompleteBloodCount
{
protected:
	float hb, ht, pt, rbc, wbc, mcv, mch, mchc, nph, lymph, esp, mns, bsi;
public:
	CompleteBloodCount()                  // taking cbc inputs
	{
		cout << "ENTERING CBC DETAILS \n \n";
		cout << "Please enter HEMOGLOBIN  (g/dL) : ";
		cin >> hb;
		cout << "Please enter HEMATOCRIT  (%) : ";
		cin >> ht;
		cout << "Please enter PLATELETS  (%) : ";
		cin >> pt;
		cout << "Please enter RED BLOOD CELLS  (*10E12/L) : ";
		cin >> rbc;
		cout << "Please enter WHITE BLOOD CELLS  (*10E12/L) : ";
		cin >> wbc;
		cout << "Please enter MCV  (fL) : ";
		cin >> mcv;
		cout << "Please enter	MCH  (pg) : ";
		cin >> mch;
		cout << "Please enter MCHC  (%) : ";
		cin >> mchc;
		cout << "Please enter NEUTROPHILIS  (%) : ";
		cin >> nph;
		cout << "Please enter LYMPHOCYTES (%) : ";
		cin >> lymph;
		cout << "Please enter EOSINPHILS (%) : ";
		cin >> esp;
		cout << "Please enter MONOCYTES (%) : ";
		cin >> mns;
		cout << "Please enter BASOPHILS  (%) : ";
		cin >> bsi;
		cout << endl;
	}
	void CBCRecord()  //  copying the data in a text file
	{
		ofstream fout;
		fout.open("Patient.txt", ios::app);
		fout << "\nCBC RECORDS: \n";
		fout << "Hemoglobin : " << hb << "\n";
		fout << "Hematocrit : " << ht << "\n";
		fout << "Platelets : " << pt << "\n";
		fout << "RBC : " << rbc << "\n";
		fout << "WBC : " << wbc << "\n";
		fout << "MCV : " << mcv << "\n";
		fout << "MCH : " << mch << "\n";
		fout << "MCHC : " << mchc << "\n";
		fout << "Neutrophilis : " << nph << "\n";
		fout << "Lymphocytes : " << lymph << "\n";
		fout << "Eosinphils : " << esp << "\n";
		fout << "Monocytes : " << mns << "\n";
		fout << "Basophilis : " << bsi << "\n";
		fout.close();
	}
};
class BasicMetabolicPanel
{
protected:
	float calcium, glucose, sodium, potassium, carbondioxide, bun, creatinine;
public:
	BasicMetabolicPanel()              //  taking bmp inputs
	{
		cout << "ENTERING BMP DETAILS \n \n";
		cout << "Please enter CALCIUM (mg/dL) : ";
		cin >> calcium;
		cout << "Please enter GLUCOSE (mmol/L) : ";
		cin >> glucose;
		cout << "Please enter SODIUM(mmol/L) : ";
		cin >> sodium;
		cout << "Please enter POTASSIUM (mmol/L) : ";
		cin >> potassium;
		cout << "Please enter CARBONDIOXIDE  (mEqL) : ";
		cin >> carbondioxide;
		cout << "Please enter BLOOD UREA NITROGEN (mg/dL) : ";
		cin >> bun;
		cout << "Please enter CREATININE (mg/dL) : ";
		cin >> creatinine;
		cout << endl;
	}
	void BMPRecord()    // ----> copying the data in a text file
	{
		ofstream fout;
		fout.open("Patient.txt", ios::app);
		fout << "\nBMP RECORDS: \n";
		fout << "Calcium : " << calcium << "\n";
		fout << "Glucose : " << glucose << "\n";
		fout << "Sodium  : " << sodium << "\n";
		fout << "Potassium : " << potassium << "\n";
		fout << "Carbondioxide : " << carbondioxide << "\n";
		fout << "B.U.N. : " << bun << "\n";
		fout << "Creatinine : " << creatinine << "\n";
		fout.close();
	}
};
class VITAMINS
{
protected:
	float vitd, vitB12;
public:
	VITAMINS()                      // taking vitamin inputs
	{
		cout << "ENTERING VIT DETAILS \n \n";
		cout << "Please enter VITAMIN D (ng/mL) : ";
		cin >> vitd;
		cout << "Please enter VITAMIN B12 (ng/mL) : ";
		cin >> vitB12;
		cout << endl;
	}
	void VITRecord()   //  copying the data in a text file
	{
		ofstream fout;
		fout.open("Patient.txt", ios::app);
		fout << "\nVIT RECORDS : \n";
		fout << "VIT D : " << vitd << "\n";
		fout << "VIT B12 : " << vitB12 << "\n\n\n";
		fout.close();
	}
};
class CBC_Ranges  // ----> getting pre-defined range values for cbc from a file
{
protected:
	float hb_min, hb_max, Ht_min, Ht_max, pt_min, pt_max, rbc_min, rbc_max;
	float wbc_min, wbc_max, mcv_min, mcv_max, mch_min, mch_max, mchc_min, mchc_max;
	float nph_min, nph_max, lymph_min, lymph_max, esp_min, esp_max, mns_min, mns_max, bsi_min, bsi_max;
public:
	CBC_Ranges()
	{
		ifstream fin;
		fin.open("cbc.txt", ios::in);
		float value;
		fin >> value; hb_min = value; fin >> value; hb_max = value;
		fin >> value; Ht_min = value; fin >> value; Ht_max = value;
		fin >> value; pt_min = value; fin >> value; pt_max = value;
		fin >> value; rbc_min = value; fin >> value; rbc_max = value;
		fin >> value; wbc_min = value; fin >> value; wbc_max = value;
		fin >> value; mcv_min = value; fin >> value; mcv_max = value;
		fin >> value; mch_min = value; fin >> value; mch_max = value;
		fin >> value; mchc_min = value; fin >> value; mchc_max = value;
		fin >> value; nph_min = value; fin >> value; nph_max = value;
		fin >> value; lymph_min = value; fin >> value; lymph_max = value;
		fin >> value; esp_min = value; fin >> value; esp_max = value;
		fin >> value; mns_min = value; fin >> value; mns_max = value;
		fin >> value; bsi_min = value; fin >> value; bsi_max = value;
		fin.close();
	}
};
class BMP_Ranges     // ----> getting pre-defined values for bmp ranges  from a file
{
protected:
	float ca_min, ca_max, gc_min, gc_max, Na_minm, Na_maxm, Na_minf, Na_maxf;
	float K_min, K_max, co2_min, co2_max, BUN_min, BUN_max, ct_min, ct_max;
public:
	BMP_Ranges()
	{
		ifstream fin;
		fin.open("bmp.txt", ios::in);
		float value;
		fin >> value; ca_min = value; fin >> value; ca_max = value;
		fin >> value; gc_min = value; fin >> value; gc_max = value;
		fin >> value; Na_minm = value; fin >> value; Na_maxm = value;
		fin >> value; Na_minf = value; fin >> value; Na_maxf = value;
		fin >> value; K_min = value; fin >> value; K_max = value;
		fin >> value; co2_min = value; fin >> value; co2_max = value;
		fin >> value; BUN_min = value; fin >> value; BUN_max = value;
		fin >> value; ct_min = value; fin >> value; ct_max = value;
		fin.close();
	}
};
class VITS_Ranges          // ----> getting pre-defined values for vitamins ranges  from a file
{
protected:
	float vitd_def, vitd_ins_min, vitd_ins_max, vitd_suff, vitd_intox;
	float vit_B12_low, vit_B12_nor_min, vit_B12_nor_max, vit_B12_high;
public:
	VITS_Ranges()
	{
		ifstream fin;
		fin.open("vitamins.txt", ios::in);
		float value;
		fin >> value; vitd_def = value; fin >> value; vitd_ins_min = value;
		fin >> value; vitd_ins_max = value; fin >> value; vitd_suff = value;
		fin >> value; vitd_intox = value; fin >> value; vit_B12_low = value;
		fin >> value; vit_B12_nor_min = value; fin >> value; vit_B12_nor_max = value;
		fin >> value; vit_B12_high = value;
		fin.close();
	}
};
// Comparing INPUTS with pre-defined Ranges
class EVALUATION : public CBC_Ranges, public BMP_Ranges, public VITS_Ranges, public BasicMetabolicPanel, public VITAMINS, public CompleteBloodCount
{
public:
	void bmp_analysis()
	{
		cout << "\n\n\n\n--------------------------BMP ANALYSIS------------------------\n\n\n\n" << endl;
		cout << "Calcium" << endl;
		if (calcium > ca_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by high calcium and the recommended medicines\n\n";
			cout << "             Diseases                    Medication      \n";
			cout << "    |Primary hyperparathyrioidism.  |   Calcimimetics   |\n";
			cout << "    |Malingnancy(cancer).           |      ------       |\n";
			cout << "    |Kidney disease.                |      ------       |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 15 DAYS \n\n NOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \n WE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";

		}
		else if (calcium < ca_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by Low calcium and the recommended medicines\n\n";
			cout << "        Diseases               Medication      \n";
			cout << "    |Muscle aches.      |       Advil                  |\n";
			cout << "    |Extreme fatigue.   |       Mpdafinil              |\n";
			cout << "    |Eczema.            |     Hydrocortisone steroids  |\n";
			cout << "    |Osteoporosis.      |       Fosamax                |\n";
			cout << "    |Denatal Problems   |       Go to Dentist          |\n";
			cout << "    |Depression.        |       Anafranil              |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 20 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";

		}
		else
		{
			cout << "   your calcium results are normal   \n";
		}
		cout << "Glucose" << endl;
		if (glucose > gc_max)
		{

			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by high glucose and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Hyperglycemia          |      Insulin                |\n";
			cout << "    |Cardiovascular disease |      Benazepril             |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 10 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (glucose < gc_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by Low glucose and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Hypoglycemia          |       Dextrose      |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 21 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your glucose results are normal   \n";
		}
		cout << "Sodium" << endl;
		if (sodium > Na_maxm)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by high sodium and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Hypernatremia         |    Loop Diuretics,Intravenous (IV) fluids   |\n";
			cout << "RECOVERY TIME: 15 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (sodium < Na_minm)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by low sodium and the recommended medicines\n\n";
			cout << "         Diseases                  Medication      \n";
			cout << "    |Hyponatremia          |      Amiodarone       |\n";
			cout << "RECOVERY TIME: 31 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your sodium results are normal   \n";
		}
		cout << "Pottassium" << endl;
		if (potassium > K_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by high Potassium and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Hyperkalemia         |     Kayalate          |\n";
			cout << "RECOVERY TIME: 16 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (potassium < K_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by low Potassium and the recommended medicines\n\n";
			cout << "        Diseases               Medication      \n";
			cout << "    |Hypokalemia         |     Kdur          |\n";
			cout << "RECOVERY TIME: 20 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your potassium results are normal   \n";
		}
		cout << "Carbon Dioxide" << endl;
		if (carbondioxide > co2_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by high Carbon Dioxide and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Hypercapnia         |     (Treatment)   Noninvasive ventilation,intubation      |\n";
			cout << "RECOVERY TIME: 25 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (carbondioxide < co2_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by low Carbon Dioxide and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Kidney Disease         |        ------           |\n";
			cout << "    |diabetic ketoacidosis  |   insulin aspart, KDur  | ";
			cout << "RECOVERY TIME: 15 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your carbon dioxide results are normal   \n";
		}
		cout << "Blood Urea Nitrogen (BUN)" << endl;
		if (bun > BUN_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by High BUN and the recommended medicines\n\n";
			cout << "        Diseases                  Medication      \n";
			cout << "    |Congestive heart failure  |   Carvedilol     |\n";
			cout << "    |Dehydration               |   Isolyte S      |\n";
			cout << "RECOVERY TIME: 20 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (bun < BUN_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by low BUN and the recommended medicines\n\n";
			cout << "         Diseases                Medication       \n";
			cout << "    |Liver Disease        |    Ursodiol          |\n";
			cout << "    |Overhydration        |    Bumex             |\n";
			cout << "RECOVERY TIME: 20 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your blood urea nitrogen results are normal   \n";
		}
		cout << "Creatinine" << endl;
		if (creatinine > ct_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by High Creatinine and the recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n";
			cout << "        |Kidney disease       |  Septra             |\n";
			cout << "RECOVERY TIME: 15 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else if (creatinine < ct_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are the diseases which can be caused by low Creatinine and the recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n";
			cout << "        |Muscular dystrophy   |  Prednisone         |\n";
			cout << "RECOVERY TIME: 12 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE\n";
		}
		else
		{
			cout << "   your creatinine results are normal   \n";
		}
	}
	void  vits_analysis()
	{
		if (vitd < vitd_def)
		{
			cout << "\n\nFollowing are the diseases which are caused by low levels if Vitamin D\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Osteoporosis            |        25-hydroxyvitamin D     |\n";
			cout << "   |Osteomalacia            |        25(OH)D                 |\n";
			cout << "   |Schizophrenia           |              .                 |\n";
			cout << "   |Rickets (in children)   |              .                 |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 56 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (vitd >= vitd_ins_min && vitd <= vitd_ins_max)
		{
			cout << "\n\nYou have borderline sufficient levels of Vitamin D.\n\n";
			cout << "           Symptoms                  Medication      \n\n";
			cout << "   |Fatigue                 |        Vitamin D Supplements   |\n";
			cout << "   |Bone Pain               |                 .              |\n";
			cout << "   |Muscle Weakness         |                 .              |\n";
			cout << "   |Depression              |                 .              |\n";
		}
		else if (vitd >= vitd_suff && vitd < vitd_intox)
		{
			cout << "\n\nYou have sufficient levels of Vitamin D. You should have no symptoms!\n\n";
		}
		else if (vitd > vitd_intox)
		{
			cout << "\n\nYour body is intoxicated with Vitamin D.\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Hypercalcemia           |        Corticosteriods         |\n";
			cout << "   |Ataxia                  |        Bisphosphonates         |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 7-14 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		if (vitB12 < vit_B12_low) {
			cout << "\n\nYour body has low levels of Vitamin B12.\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Anemia                  |        Hydroxocobalamin        |\n";
			cout << "   |Neurological            |        Cyanocobalamin          |\n";
			cout << "   |Disorders               |              .                 |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 6-12 MONTHS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (vitB12 > vit_B12_nor_min && vitB12 < vit_B12_nor_max)
		{
			cout << "\n\nYou have normal levels of Vitamin B12.\n\n";
		}
		else if (vitB12 > vit_B12_high)
		{
			cout << "\n\nYour body should be fine as high levels of Vitamin B12 are considered safe.\n\n";
		}
	}

	void cbc_analysis()
	{
		cout << "\n\n\n\n--------------------------CBC ANALYSIS------------------------\n\n\n\n";
		cout << "HEMOGLOBIN";
		if (hb > hb_min && hb < hb_max)
		{
			cout << "\n\nYou have normal levels of Hemoglobin in your body.\n\n";
		}
		else
			if (hb < hb_min)
			{
				cout << "\n\n---------------------------D/M-------------------------";
				cout << "\n\nFollowing are diseases which can be caused by low hemoglobin and recommended medicines\n\n";
				cout << "           Diseases                  Medication                       \n\n";
				cout << "   |Aplastic anemia.        |        cyclosporine                    |\n";
				cout << "   |Cancer.                 |         ------                         |\n";
				cout << "   |Chronic kidney diseas   |        Enalapril                       |\n";
				cout << "   |Cirrhosis               |        ursodiol                        |\n";
				cout << "   |Hypothyroidism          |        levothyroxine                   |\n";
				cout << "   |Iron deficiency anemia  |        Ferrous sulfate                 |\n";
				cout << "   |Lead poisoning          |        EDTA chelation therapy          |\n";
				cout << "   |Vit deficiency anemia   |        supplements and changes in diet.|\n";
				cout << "----------------------Time Duration--------------------\n";
				cout << "RECOVERY TIME: 15 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";

			}
			else
				if (hb > hb_max)
				{
					cout << "\n\n---------------------------D/M-------------------------";
					cout << "\nFollowing are diseases which can be caused by high hemoglobin and recommended medicines\n\n";
					cout << "           Diseases                  Medication      \n\n";
					cout << "   |Congenital heart disease|         Digoxin         |\n";
					cout << "   |Dehydration.            |         Isolyte S       |\n";
					cout << "   |Emphysema.              |         Bronchodilators |\n";
					cout << "   |Heart failure.          |             ------      |\n";
					cout << "   |Kidney cancer.          |             ------      |\n";
					cout << "   |Liver cancer.           |             ------      |\n";
					cout << "   |Polycythemia vera.      |         hydroxyurea     |\n";
					cout << "----------------------Time Duration--------------------\n";
					cout << "RECOVERY TIME: 12 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";

				}
		cout << "\n\nHEMATOCRIT";
		if (ht > Ht_max)
		{

			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high hematocrit and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n";
			cout << "   |Dehydration             |         Isolyte S          |\n";
			cout << "   |polycythemia ver        |         Polycythemia vera. |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 6 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";

		}
		else if (ht < Ht_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low hematocrit and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n";
			cout << "   |Anemia                      |    folic acid     |\n";
			cout << "   |leukemia                    |    Azacitidine    |\n";
			cout << "   |Vit or mineral deficiencies |    Methylcobalamin|\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 5 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal level of Hematocrit in your body.\n\n";
		}
		cout << "\n\nPLATELATES";
		if (pt < pt_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low Platelets and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Thrombocytopenia            |    corticosteroid     |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 8 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (pt > pt_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high platelets and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Thrombocytocis              |      hydroxyurea plus aspirin|\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 9 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal level of Platelets in your body.\n\n";
		}
		cout << "\n\nRED BLOOD CELLS";
		if (rbc > rbc_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high red blood cells and recommended medicines\n\n";
			cout << "           Diseases                    Medication      \n\n";
			cout << "   |Heart failure               |       ------        |\n";
			cout << "   |Polycythemia vera           |      hydroxyurea    |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 16 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (rbc < rbc_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low red blood cells and recommended medicines\n\n";
			cout << "           Diseases                     Medication      \n\n";
			cout << "  |Aplastic anemia              |      cyclosporine    |\n";
			cout << "  |Cancer                       |      ------          |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 3 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of Red Blood Cells in your body.\n\n";
		}
			cout << "\n\nWHITE BLOOD CELLS";
		if (wbc > wbc_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high white blood cell and recommended medicines\n\n";
			cout << "           Diseases                    Medication      \n\n";
			cout << "   |Leukemia                    |     Azacitidine     |\n";
			cout << "   |Lymphoma                    |     Acalabrutinib   |\n";
			cout << "   |polycythemia vera           |     hydroxyurea     |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 18 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (wbc < wbc_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low white blood cells and recommended medicines\n\n";
			cout << "           Diseases                    Medication      \n\n";
			cout << "  |Bone marrow disorders        |      sargramostim    |\n";
			cout << "  |Cancer                       |      ------          |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 89 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of White Blood Cells in your body.\n\n";
		}
		cout << "\n\nMCV";
		if (mcv < mcv_min)
		{

			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low mcv and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "  |microcytic anemia            |    iron and vit C supplements   |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 30 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (mcv > mcv_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high mcv and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "  |Macrocytic anemia            |    Folate antagonists          |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 55 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of MCV in your body.\n\n";
		}
		cout << "\n\nMCH";
		if (mch > mch_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high mch and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "  |Macrocytic anemia            |    Folate antagonists         |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 20 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (mch < mch_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low mch and recommended medicines\n\n";
			cout << "           Diseases                   Medication      \n\n";
			cout << "  |Iron deficiency anemia.      |     Ferrous sulfate           |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 25 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of MCH in your body.\n\n";
		}
		cout << "\n\nMCHC";
		if (mchc < mchc_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low mchc and recommended medicines\n\n";
			cout << "           Diseases                               Medication      \n\n";
			cout << "  |Hypochromic microcytic anemia      |     iron and vitamin C supplements.       |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 5 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}

		else if (mchc > mchc_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high mchc and recommended medicines\n\n";
			cout << "           Diseases                        Medication      \n\n";
			cout << "  | Autoimmune hemolytic anemia        |     Dapsone        |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 2 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of MCHC in your body.\n\n";
		}
		cout << "\n\nNEUTROPHILIS";
		if (nph > nph_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high NEUTROPHILIS  and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "  | sinus infections        |     anti-inflammatory drugs    |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 87 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (nph < nph_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low NEUTROPHILIS and recommended medicines\n\n";
			cout << "           Diseases                Medication      \n\n";
			cout << "   |Hepatitis                |     entecavir    |\n";
			cout << "   |Tuberculosis             |     Isoniazid    |\n";
			cout << "   |sepsis,                  |     ceftriaxone  |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 1 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of NEUTROPHILS in your body.\n\n";
		}
		cout << "\n\nLYMPHOCYTES";
		if (lymph < lymph_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low lymphocytes and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Lymphocytopenia          |        azathioprine  |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 78 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (lymph > lymph_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high lymphocytes and recommended medicines\n\n";
			cout << "           Diseases                  Medication      \n\n";
			cout << "   |Blood cancer            |        ------         |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 4 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of LYMPHOCYTES in your body.\n\n";
		}
		cout << "\n\nEOSINPHILS";
		if (esp > esp_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high eosinphils and recommended medicines\n\n";
			cout << "    Diseases                  Medication      \n\n";
			cout << "   |cancer        |           ------          |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME: 14 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (esp < esp_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low leosinphils and recommended medicines\n\n";
			cout << "    Diseases              Medication      \n\n";
			cout << "   |Cortisol       |      Ashwagandha Extract   |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME:12 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of EOSINOPHILS in your body.\n\n";
		}
		cout << "\n\nMONOCYTES";
		if (mns < mns_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low monocytes and recommended medicines\n\n";
			cout << "           Diseases                    Medication      \n\n";
			cout << "  |Bone marrow disorders        |        cyclosporine           |\n";
			cout << "  |bloodstream infection        |       antimicrobial therap    |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME:15 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (mns > mns_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high monocytes and recommended medicines\n\n";
			cout << "           Diseases                       Medication      \n\n";
			cout << "   |infectious mononucleosis         |     ------        |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME:12 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of MONOCYTES in your body.\n\n";
		}
		cout << "\n\nBASOPHILS";
		if (bsi > bsi_max)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by high Basophils and recommended medicines\n\n";
			cout << "           Diseases                          Medication      \n\n";
			cout << "   |Myeloproliferative disorders     |      Chemotherapy    |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME:18 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else if (bsi < bsi_min)
		{
			cout << "\n\n---------------------------D/M-------------------------";
			cout << "\n\nFollowing are diseases which can be caused by low Basophils and recommended medicines\n\n";
			cout << "           Diseases                          Medication      \n\n";
			cout << "   |chronic inflammation             |       aspirin        |\n";
			cout << "----------------------Time Duration--------------------\n";
			cout << "RECOVERY TIME:21 DAYS \n\nNOTE: IF PATIENT DOES NOT RECOVER FROM GIVEN MEDICATION IN RECOVERY DURATION \nWE SUGGEST YOU TEST AGAIN AND REPEAT THE PROCEDURE”.\n";
		}
		else
		{
			cout << "\n\nYou have normal levels of BASOPHILS in your body.\n\n";
		}
	}
	void cbcdisplay() {}    // function body in child class
	void BMPDisp() {}     // function body in child class
	void VitaminDisp() {}  // function body in child class
};
class DISPLAY : public EVALUATION           // ---> printing the ranges for reference purpose for user along with the result
{
public:
	void cbcdisplay()
	{
	
		cbc_analysis();
		// displaying cbc ranges  and your result
		cout << " YOUR CBC RESULT AND THE REFERENCE RANGES. \n\n";

		cout << "TEST                         |                  RESULT                               |      REFERENCE RANGES\n\n";
		cout << "Hemoglobin            |      " << hb << "                                   |      low " << hb_min << "\n\n";
		cout << "Hemoglobin            |                                                              |    Normal " << hb_min << "-" << hb_max << "\n\n";
		cout << "Hemoglobin            |                                                               |      High >=" << hb_max << "\n\n";
		cout << "Hematocrit              |      " << ht << " (%%)                           |      low <" << Ht_min << "\n\n";
		cout << "Hematocrit              |                                                               |    Normal " << Ht_min << "-" << Ht_max << "\n\n";
		cout << "Hematocrit              |                                                                |      High >=%" << Ht_max << "\n\n";
		cout << "Platelets                   |      " << pt << " (%%)                           |      low <" << pt_min << "\n\n";
		cout << "Platelets                   |                                                               |    Normal " << pt_min << "-" << pt_max << "\n\n";
		cout << "Platelets                   |                                                                |      High >=" << pt_max << "\n\n";
		cout << "RBC                           |      " << rbc << " (*10E12/L)                |      low <" << rbc_min << "\n\n";
		cout << "RBC                           |                                                                |    Normal " << rbc_min << "-" << rbc_max << "\n\n";
		cout << "RBC                           |                                                                 |      High >=" << rbc_max << "\n\n";
		cout << "WBC                         |      " << wbc << " (*109/L)                    |      low <" << wbc_min << "\n\n";
		cout << "WBC                         |                                                                 |    Normal " << wbc_min << "-" << wbc_max << "\n\n";
		cout << "WBC                         |                                                                 |      High >=" << wbc_max << "\n\n";
		cout << "MCV                         |     " << mcv << " (fL)                              |      low <" << mcv_min << "\n\n";
		cout << "MCV                         |                                                                  |    Normal " << mcv_min << "-" << mcv_max << "\n\n";
		cout << "MCV                        |                                                                   |      High >=" << mcv_max << "\n\n";
		cout << "MCH                        |      " << mch << "(pg)                             |      low <" << mch_min << "\n\n";
		cout << "MCH                        |                                                                   |    Normal " << mch_min << "-" << mch_max << "\n\n";
		cout << "MCH                        |                                                                   |      High >=" << mch_max << "\n\n";
		cout << "MCHC                     |      " << mchc << " (g/dL)                        |      low <" << mchc_min << "\n\n";
		cout << "MCHC                     |                                                                   |    Normal " << mchc_min << "-" << mchc_max << "\n\n";
		cout << "MCHC                     |                                                                    |      High >=" << mchc_max << "\n\n";
		cout << "Neutrophilis           |     " << nph << " (%%)                             |      low <" << nph_min << "\n\n";
		cout << "Neutrophilis           |                                                                   |    Normal " << nph_min << "-" << nph_max << "\n\n";
		cout << "Neutrophilis           |                                                                   |      High >=" << nph_max << "\n\n";
		cout << "Lymphocytes         |      " << lymph << " (%%)                        |      low <" << lymph_min << "\n\n";
		cout << "Lymphocytes         |                                                                    |    Normal " << lymph_min << "-" << lymph_max << "\n\n";
		cout << "Lymphocytes         |                                                                    |      High >=" << lymph_max << "\n\n";
		cout << "Eosinphils              |      " << esp << "(%%)                               |      low <" << esp_min << "\n\n";
		cout << "Eosinphils              |                                                                     |    Normal " << esp_min << "-" << esp_max << "\n\n";
		cout << "Eosinphils              |                                                                     |      High >=" << esp_max << "\n\n";
		cout << "Monocytes            |      " << mns << " (%%)                             |      low <" << mns_min << "\n\n";
		cout << "Monocytes            |                                                                     |    Normal " << mns_min << "-" << mns_max << "\n\n";
		cout << "Monocytes            |                                                                     |      High >=" << mns_max << "\n\n";
		cout << "Basophils               |      " << bsi << " (%%)                                |      low <" << bsi_min << "\n\n";
		cout << "Basophils               |                                                                      |    Normal " << bsi_min << "-" << bsi_max << "\n\n";
		cout << "Basophilis               |                                                                     |      High >=" << bsi_max << "\n\n";

	}
	void BMPDisp()
	{
		
		bmp_analysis();
		//displaying bmp ranges and your result
		cout << " YOUR BMP RESULT AND THE REFERENCE RANGES. \n\n";

		cout << "TEST                      |      RESULT                                             |      REFERENCE RANGES\n\n";
		cout << "Calcium                |      " << calcium << " (mg/dL)             |      Low < " << ca_min << "\n\n";
		cout << "Calcium                |                                                                 |      Normal  " << ca_min << "- " << ca_max << "\n\n";
		cout << "Calcium                |                                                                 |      High > " << ca_max << "\n\n";
		cout << "Glucose                |      " << glucose << " (mmol/L)            |      Low < " << gc_min << "\n\n";
		cout << "Glucose                |                                                                  |      Normal " << gc_min << " - " << gc_max << "\n\n";
		cout << "Glucose                |                                                                  |      High > " << gc_max << "\n\n";
		cout << "Sodium                |         " << sodium << "(mmol/L)             |      Low < " << Na_minm << "\n\n";
		cout << "Sodium                |                                                                    |      Normal " << Na_minm << " - " << Na_maxm << "\n\n";
		cout << "Sodium                |                                                                    |      High > " << Na_maxm << "\n\n";
		cout << "Potassium            |     " << potassium << " (mmol/L)          |      Low < " << K_min << "\n\n";
		cout << "Potassium           |                                                                    |      Normal " << K_min << " - " << K_max << "\n\n";
		cout << "Potassium           |                                                                    |      High >" << K_max << "\n\n";
		cout << "Carbon Dioxide  |  " << carbondioxide << " (mEqL)           |      Low < " << co2_min << "\n\n";
		cout << "Carbon Dioxide  |                                                                    |      Normal " << co2_min << " - " << co2_max << "\n\n";
		cout << "Carbon Dioxide  |                                                                     |      High > " << co2_max << "\n\n";
		cout << "BUN                      |           " << bun << " (mg/dL)                   |      Low < " << BUN_min << "\n\n";
		cout << "BUN                     |                                                                     |      Normal " << BUN_min << " - " << BUN_max << "\n\n";
		cout << "BUN                     |                                                                     |      High > " << BUN_max << "\n\n";
		cout << "Creatinine           |    " << creatinine << " (Mg/dL)                |      Low < " << ct_min << "\n\n";
		cout << "Creatinine          |                                                                       |      Normal " << ct_min << " - " << ct_max << "\n\n";
		cout << "Creatinine          |                                                                       |      High > " << ct_max << "\n\n";

	}
	void vitaminDisp()
	{
		
		vits_analysis();
		// displaying vitamins ranges and your result
		cout << " YOUR VITAMIN RESULT AND THE REFERENCE RANGES. \n\n";
		 
		cout << "\nTEST                |                RESULT                          |      REFERENCE RANGES\n\n";
		cout << "Vitamin D           |           " << vitd << " (ng/mL)     |      Deficiency < " << vitd_def << "\n\n";
		cout << "Vitamin D           |                                                       |      Insuffciency " << vitd_ins_min << " - " << vitd_ins_max << "\n\n";
		cout << "Vitamin D           |                                                       |      Sufficiency >= " << vitd_suff << "\n\n";
		cout << "Vitamin D           |                                                       |      Intoxication >= " << vitd_intox << "\n\n";
		cout << "Vitamin B12       |        " << vitB12 << " (ng/mL)    |      Low < " << vit_B12_low << "\n\n";
		cout << "Vitamin B12       |                                                       |      Normal " << vit_B12_nor_min << " - " << vit_B12_nor_max << "\n\n";
		cout << "Vitamin B12       |                                                       |      High > " << vit_B12_high << "\n\n";
	}

};

int main()
{
	string name;
	char gender;
	int id;
	cout << "Please enter your name : ";
	//cin.ignore();
	getline(cin,name);  // for multi-word name  
	cout << "Please enter your gender (M/m for male and F/f for female) : ";
	cin >> gender;
	cout << "Please enter the ID to be alloted to the patient. ";
	cin >> id;
	PATIENT person1(id,name,gender);      // Patient info entered 
	
	DISPLAY patient1;     // Patient object made for analysis based on user inputs
	DISPLAY* ptr;            
	ptr = &patient1;
	ptr->cbcdisplay();
	cin.get();
	cin.ignore();
	system("CLS");
	ptr->BMPDisp();
	cin.get();
	cin.ignore();
	system("CLS");
	ptr->vitaminDisp();
	cin.get();
	cin.ignore();
	system("CLS");
	
	// Copying relevant information into a text file
	person1.StoreInfo();
	ptr->CBCRecord();
	ptr->BMPRecord();
	ptr->VITRecord();

	// + operator overloaded to get next appointment
	date Next(14, 0, 0);  // next appointment is after 2 weeks 
	date NextAppointment;   // to store result
	NextAppointment = today + Next;


	cout << "Your next appoinment is set for : " << NextAppointment.getday()<<"/"<< NextAppointment.getmonth()<<"/"<< NextAppointment.getyear();
	cout << endl << endl;

	cout << "Take Care of Yourself and Get Well Soon.";
	cout << endl << endl;
	return 0;
}