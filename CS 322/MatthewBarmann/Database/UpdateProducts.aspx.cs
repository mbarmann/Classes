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
    public partial class UpdateProducts : System.Web.UI.Page
    {
        string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                try
                {
                    ShowProductList();
                    //ShowProductTable();
                }
                catch
                {
                }
            }
            else
            {
                /*//ddlProductId.Rows.Clear();
                for (int i = 0; i < ProductTable.Rows.Count; i++)
                {
                    ProductTable.Rows.RemoveAt(i);
                }
                ShowProductList();
                ShowProductTable();*/
            }
        }
        private void ShowProductList()
        {
            string ShowAllProducts = "ShowAllProducts";
            ddlProductId.Items.Clear();
            ListItem firstItem = new ListItem();
            firstItem.Text = "Select a Product";
            firstItem.Value = "0";
            ddlProductId.Items.Add(firstItem);
            ddlProductId.SelectedIndex = 0;
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd1 = new SqlCommand(ShowAllProducts, con);
            cmd1.CommandType = CommandType.StoredProcedure;
            SqlDataReader readerSelect;
            try
            {
                con.Open();
                readerSelect = cmd1.ExecuteReader();
                while (readerSelect.Read())
                {
                    ListItem newItem = new ListItem();
                    newItem.Text = readerSelect["name"].ToString();
                    newItem.Value = readerSelect["product_ID"].ToString();
                    ddlProductId.Items.Add(newItem);
                }
                readerSelect.Close();
                con.Close();
            }
            catch (Exception err)
            {
                UpdateResponse.Text = "Error reading list of products. <br />";
                UpdateResponse.Text += err.Message + "<br />";
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    UpdateResponse.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }

        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(CS);
            //SqlCommand cmd = new SqlCommand("ShowAllProducts", con);
            SqlCommand cmd2 = new SqlCommand("SELECT * FROM Products WHERE product_ID = " + ddlProductId.SelectedItem.Value, con);
            //cmd.CommandText = "SELECT * FROM Products WHERE ProductID = " + ddlProductId.SelectedItem.Value;
            SqlDataReader reader;
            try
            {
                con.Open();
                reader = cmd2.ExecuteReader();
                while (reader.Read())
                {
                    product_ID.Text = reader["product_ID"].ToString();
                    name.Text = reader["name"].ToString();
                    category_ID.Text = reader["category_ID"].ToString();
                    category_name.Text = reader["category_name"].ToString();
                    description.Text = reader["description"].ToString();
                    inventory_num.Text = reader["inventory_num"].ToString();
                    price.Text = reader["price"].ToString();
                    cost.Text = reader["cost"].ToString();
                    weight.Text = reader["weight"].ToString();
                    image.Text = reader["image"].ToString();
                    thumbnail.Text = reader["thumbnail"].ToString();
                }
                reader.Close();
                con.Close();
            }
            catch (Exception err)
            {
                this.UpdateResponse.Text = "Records not available: <br/>" + "Error: " + err.Message;
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    UpdateResponse.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd3 = new SqlCommand("UpdateProductParam", con);
            cmd3.CommandType = CommandType.StoredProcedure;
            cmd3.CommandText = "UpdateProductParam";
            SqlDataReader reader;
            try
            {
                con.Open();

                cmd3.Parameters.AddWithValue("@ProductID", product_ID.Text);
                cmd3.Parameters.AddWithValue("@ProductName", name.Text);
                cmd3.Parameters.AddWithValue("@CategoryID", category_ID.Text);
                cmd3.Parameters.AddWithValue("@CategoryName", category_name.Text);
                cmd3.Parameters.AddWithValue("@Description", description.Text);
                cmd3.Parameters.AddWithValue("@Inventory", inventory_num.Text);
                cmd3.Parameters.AddWithValue("@Cost", cost.Text);
                cmd3.Parameters.AddWithValue("@Price", price.Text);
                cmd3.Parameters.AddWithValue("@Weight", weight.Text);
                cmd3.Parameters.AddWithValue("@ProductImage", image.Text);
                cmd3.Parameters.AddWithValue("@ProductThumbnail", thumbnail.Text);

                int myReturn = cmd3.ExecuteNonQuery();
                this.UpdateResponse.Text = myReturn + " record updated: <br/>";
                con.Close();
            }
            catch (Exception err)
            {
                this.UpdateResponse.Text = "Records not available: <br/>" + "Error: " + err.Message;
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    UpdateResponse.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }
    }
}