#include <iostream>
using namespace std;
int main() {
  // The working flow is according to my understanding from the question statement and rest is common known practices. If I misunderstood any specific requirment, I can easily modify the code as required.
  double price_A = 50.0;
  double price_B = 30.0;
  double price_C = 20.0;
  int quantity_A, quantity_B, quantity_C;
  int stockA = 10, stockB = 5, stockC = 8;

  cout << "Enter the quantity of the Product A: ";
  cin >> quantity_A;
  bool A_in_stock_ordered = false;
  while(!A_in_stock_ordered) {

  if (quantity_A > stockA) {
    cout << "Sorry, only " << stockA << " units of Product A are available.\n";
    cout << "Enter the quantity of the Product A: ";
    cin >> quantity_A;
    A_in_stock_ordered = false;
  }
  else {
    A_in_stock_ordered = true;
  }
  }

  cout << "Enter the quantity of the Product B: ";
  cin >> quantity_B;
  bool B_in_stock_ordered = false;
  while (!B_in_stock_ordered) {
  
  if (quantity_B > stockB) {
    cout << "Sorry, only " << stockB << " units of Product B are available.\n";
    cout << "Enter the quantity of the Product B: ";
    cin >> quantity_B;
    B_in_stock_ordered = false;
  }
  else {
    B_in_stock_ordered = true;
  }
  }

  cout << "Enter the quantity of the Product C: ";
  cin >> quantity_C;
  bool C_in_stock_ordered = false;
  while(!C_in_stock_ordered) {
  
  if (quantity_C > stockC) {
    cout << "Sorry, only " << stockC << " units of Product C are available.\n";
    cout << "Enter the quantity of the Product C: ";
    cin >> quantity_C;
    C_in_stock_ordered = false;
  }
  else {
    C_in_stock_ordered = true;
  }
  }


  int payment_method;
  cout << "Select a payment method (1 for Credit Card, 2 for PayPal, 3 for Cash): ";
  cin >> payment_method;

  double total = price_A * quantity_A + price_B * quantity_B + price_C * quantity_C;
//   cout << "Total cost: $" << total << endl;

  double discounted_total = (total > 200)? (total * 0.90):total;
  if ((discounted_total - total) == 0) {
    // cout << "You were not eligible for discount.\n";
  }
  else {
    // cout << "Total after discount: $" << discounted_total << endl;
  }

  double shipping_cost = (discounted_total < 150)? 15.0 : 0.0;
  double total_with_shipping = discounted_total + shipping_cost;

  int customer_type;
  cout << "Enter customer type (1 for Regular, 2 for VIP): ";
  cin >> customer_type;

  double final_amount = (customer_type == 2)? total_with_shipping * 0.95 : total_with_shipping;
//   cout << "Total after customer discount: $" << final_amount << endl;

  string coupon_code;
  cout << "Enter a coupon code (if any, otherwise enter no): ";
  cin >> coupon_code;

  double coupon_discount = (coupon_code == "SAVE10") ? 10.0 : 0.0;
  double total_after_coupon = final_amount - coupon_discount;

//   cout << "Total after all discounts and shipping: $" << total_after_coupon << endl;

//   cout << "(Your shipping cost is: $" << shipping_cost << ")" << endl;

  int location;
  cout << "Enter your location (1, 2, or 3): ";
  cin >> location;

  double tax_rate = (location == 1) ? 0.05 :(location == 2) ? 0.10 : 0.08;
  double total_with_tax = total_after_coupon * (1 + tax_rate);

//   cout << "Total after applying sales tax: $" << total_with_tax << endl;


  double transaction_fee = (payment_method == 1) ? total_with_tax * 0.02 :
                            (payment_method == 2) ? total_with_tax * 0.03 : 0.0;
  double total_after_payment = total_with_tax + transaction_fee;
//   cout << "Total after applying transaction fee: $" << total_after_payment << endl;

  int loyality_points = (total_after_coupon > 300)? 50 : 20;
//   cout << "Loyalty points earned: " << loyality_points << endl;

  cout << "Order Summary:\n";
  cout << "Product A (x" << quantity_A << "): $" << price_A * quantity_A << endl;
  cout << "Product B (x" << quantity_B << "): $" << price_B * quantity_B << endl;
  cout << "Product C (x" << quantity_C << "): $" << price_C * quantity_C << endl;

  cout << "Subtotal: $" << total << endl;
  cout << "Discount: $" << total - discounted_total << endl;
  cout << "Shipping: $" << shipping_cost << endl;
  cout << "Transaction Fee: $" << transaction_fee << endl;
  cout << "Coupon Discount: $" << coupon_discount << endl;
  cout << "Sales Tax: $" << total_with_tax - total_after_coupon << endl;
  cout << "Total Amount to Pay: $" << total_with_tax << endl;
  return 0;
}
