# C_Program-Warehouse-inventory-system
A simple C program that allows users to input and manage weekly stock data for warehouse products. It calculates total and average inventory, identifies the maximum stock level, and estimates insurance costs.


# Warehouse Inventory Management System in C

## 📦 Overview

This is a simple inventory management system written in **C**, developed as part of a university assignment. The program simulates tracking incoming stock quantities for **3 products over a 7-day week** (Monday to Sunday). It provides useful analytics like weekly totals, averages, insurance cost estimates, and identifies the highest inventory values.

## 🧠 Features

- 📥 Input stock quantities per product and per day (with validation)
- 📊 Display a formatted inventory table
- 🧮 Calculate:
  - Weekly totals per product
  - Average stock per product
  - Maximum stock with the corresponding product and day
  - Insurance costs per product based on predefined unit prices
- 💶 Identify the product with the lowest insurance cost

## 🧾 Insurance Pricing

| Product | Cost per Unit (€) |
|---------|-------------------|
| #1      | 10                |
| #2      | 14                |
| #3      | 20                |

## 🛠️ How It Works

The program is modular and consists of the following main functions:

- `Dedomena()`: Collects and validates user input
- `Emfanisi_Pinaka()`: Prints the weekly inventory table
- `Evdomadiaio_Apothema()`: Calculates weekly totals
- `Megisto_Apothema()`: Identifies the maximum stock value
- `Mesos_Oros_Apothematos_proiontos()`: Computes average inventory per product
- `Ypologismos_Asfalisis_Proiodwn()`: Calculates insurance costs and identifies the cheapest one

## 📂 File Structure

- `main.c`: The full source code of the program
- `README.md`: This documentation file

## 🧪 Example Output

Προϊόν	Δευ	Τρι	Τετ	Πεμ	Παρ	Σαβ	Κυρ
#1	30	25	20	15	10	5	0
#2	50	40	35	20	10	5	5
#3	60	45	50	30	25	20	10

Product #3 had the highest stock: 60 units on Monday.
Average stock:

    Product #1: 15

    Product #2: 23.57

    Product #3: 34.28

Insurance costs:

    Product #1: €105.00

    Product #2: €165.00

    Product #3: €240.00
    Cheapest insurance: Product #1


## 📌 Notes

- Only **positive integer inputs** are accepted.
- Greek day names and labels are used for formatting consistency with original specifications.
- Code is written for educational purposes and can be expanded or improved for real-world use.

## 📚 Requirements

- C compiler (e.g., `gcc`)
- Works on Linux, Windows, or macOS terminals

## 🚀 How to Compile and Run

```bash
gcc main.c -o warehouse
./warehouse

👨‍💻 Author

Kosmas Nick – Student of Informatics at the Hellenic Open University
