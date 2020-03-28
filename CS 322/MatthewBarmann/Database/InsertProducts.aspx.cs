using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MatthewBarmann.Pages
{
    public partial class InsertProducts : System.Web.UI.Page
    {
        private string insertSQL;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                ShowProductTable();
            }
            else
            {
                for (int i = 1; i < ProductTable.Rows.Count; i++)
                {
                    ProductTable.Rows.RemoveAt(i);
                }
                ShowProductTable();
            }
        }
        protected void btnInsert_Click(object sender, EventArgs e)
        {
            if ((TextBox1.Text == null) || (TextBox1.Text == "") ||
               (TextBox2.Text == null) || (TextBox2.Text == "") ||
               (TextBox3.Text == null) || (TextBox3.Text == "") ||
               (TextBox4.Text == null) || (TextBox4.Text == "") ||
               (TextBox5.Text == null) || (TextBox5.Text == "") ||
               (TextBox6.Text == null) || (TextBox6.Text == "") ||
               (TextBox7.Text == null) || (TextBox7.Text == "") ||
               (TextBox8.Text == null) || (TextBox8.Text == "") ||
               (TextBox9.Text == null) || (TextBox9.Text == "") ||
               (TextBox10.Text == null) || (TextBox10.Text == "") ||
               (TextBox11.Text == null) || (TextBox11.Text == ""))
            {
                Message.Text =
                   "You can't leave the selection blank or empty";
            }
            else
            {
                InsertProduct();
            }
            ShowProductTable();
        }
        private void InsertProduct()
        {
            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand("InsertProducts", con);
            cmd.Parameters.AddWithValue("@ProductID", TextBox1.Text);
            cmd.Parameters.AddWithValue("@ProductName", TextBox2.Text);
            cmd.Parameters.AddWithValue("@CategoryID", TextBox3.Text);
            cmd.Parameters.AddWithValue("@CategoryName", TextBox4.Text);
            cmd.Parameters.AddWithValue("@Description", TextBox5.Text);
            cmd.Parameters.AddWithValue("@Inventory", TextBox6.Text);
            cmd.Parameters.AddWithValue("@Cost", TextBox7.Text);
            cmd.Parameters.AddWithValue("@Price", TextBox8.Text);
            cmd.Parameters.AddWithValue("@Weight", TextBox9.Text);
            cmd.Parameters.AddWithValue("@ProductImage", TextBox10.Text);
            cmd.Parameters.AddWithValue("@ProductThumbnail", TextBox11.Text);
            int valueReturned = 0;
            try
            {
                con.Open();
                valueReturned = cmd.ExecuteNonQuery();
                Message.Text = valueReturned.ToString() + " record inserted.";
            }
            catch (Exception err)
            {
                Message.Text = "Error inserting into list of products. <br />";
                Message.Text += err.Message + "<br />" + insertSQL;
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    Message.Text += "The Connection is now " + con.State.ToString();
                }
            }
            finally
            {
            }
        }
        private void ShowProductTable()
        {
            for (int i = 1; i < ProductTable.Rows.Count; i++)
            {
                ProductTable.Rows.RemoveAt(i);
            }

            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand("ShowAllProducts", con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader readerSelect;
            TableCell tempCell1, tempCell2, tempCell3, tempCell4, tempCell5,
              tempCell6, tempCell7, tempCell8, tempCell9, tempCell10, tempCell11;
            string ImagePath = "/images/";
            try
            {
                con.Open();
                readerSelect = cmd.ExecuteReader();
                while (readerSelect.Read())
                {
                    TableRow tempRow = new TableRow();
                    tempCell1 = new TableCell();
                    tempCell1.Text = readerSelect["product_ID"].ToString();
                    tempCell2 = new TableCell();
                    tempCell2.Text = readerSelect["name"].ToString();
                    tempCell3 = new TableCell();
                    tempCell3.Text = readerSelect["category_ID"].ToString();
                    tempCell4 = new TableCell();
                    tempCell4.Text = readerSelect["category_name"].ToString();
                    tempCell5 = new TableCell();
                    tempCell5.Text = readerSelect["description"].ToString();
                    tempCell6 = new TableCell();
                    tempCell6.Text = readerSelect["inventory_num"].ToString();
                    tempCell7 = new TableCell();
                    tempCell7.Text = readerSelect["cost"].ToString();
                    tempCell8 = new TableCell();
                    tempCell8.Text = readerSelect["price"].ToString();
                    tempCell9 = new TableCell();
                    tempCell9.Text = readerSelect["weight"].ToString();
                    tempCell10 = new TableCell();
                    tempCell10.Text = readerSelect["image"].ToString();
                    tempCell11 = new TableCell();
                    tempCell11.Text = readerSelect["thumbnail"].ToString();
                }
                readerSelect.Close();
                con.Close();
            }
            catch (Exception err)
            {
                Message.Text = "Error reading list of products. <br />";
                Message.Text += err.Message + "<br />";
                if (con.State.ToString() == "Open")
                {
                    con.Close(); Message.Text += "The Connection is now" + con.State.ToString();
                    Message.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }
    }
}