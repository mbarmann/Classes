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
    public partial class DeleteProducts : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                ShowProductList();
                ShowProductTable();
            }
            else
            {
                //ddlProductList.Rows.Clear();
                for (int i = 0; i < ProductTable.Rows.Count; i++)
                {
                    ProductTable.Rows.RemoveAt(i);
                }
                ShowProductList();
                ShowProductTable();
            }
        }
        private void ShowProductTable()
        {
            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            string DisplayProductTable = "DisplayProductTable";
            ProductTable.Controls.Clear();
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand(DisplayProductTable, con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader reader; TableCell tempCell1, tempCell2, tempCell3, tempCell4, tempCell5, tempCell6, tempCell7, tempCell8, tempCell9, tempCell10, tempCell11;
            string ImagePath = "/images/";
            // Use Exception handling and make sure to indent your code! 
            try
            {
                con.Open();
                reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    TableRow tempRow = new TableRow();
                    tempCell1 = new TableCell();
                    tempCell1.Text = reader["product_ID"].ToString();
                    tempCell2 = new TableCell();
                    tempCell2.Text = reader["name"].ToString();
                    tempCell3 = new TableCell();
                    tempCell3.Text = reader["category_ID"].ToString();
                    tempCell4 = new TableCell();
                    tempCell4.Text = reader["category_name"].ToString();
                    tempCell5 = new TableCell();
                    tempCell5.Text = reader["description"].ToString();
                    tempCell6 = new TableCell();
                    tempCell6.Text = reader["inventory_num"].ToString();
                    tempCell7 = new TableCell();
                    tempCell7.Text = reader["price"].ToString();
                    tempCell8 = new TableCell();
                    tempCell8.Text = reader["cost"].ToString();
                    tempCell9 = new TableCell();
                    tempCell9.Text = reader["weight"].ToString();
                    tempCell10 = new TableCell();
                    System.Web.UI.WebControls.Image CatPicture = new System.Web.UI.WebControls.Image();
                    CatPicture.Width = 100; CatPicture.Height = 100;
                    CatPicture.ImageUrl = String.Format(ImagePath, 0, reader["image"].ToString());
                    tempCell10.Controls.Add(CatPicture);
                    tempCell11 = new TableCell();
                    System.Web.UI.WebControls.Image CatThumb = new System.Web.UI.WebControls.Image();
                    CatThumb.Width = 50; CatThumb.Height = 50;
                    CatThumb.ImageUrl = String.Format(ImagePath, 0, reader["thumbnail"].ToString());
                    tempCell11.Controls.Add(CatThumb);
                    tempRow.Cells.Add(tempCell1);
                    tempRow.Cells.Add(tempCell2);
                    tempRow.Cells.Add(tempCell3);
                    tempRow.Cells.Add(tempCell4);
                    tempRow.Cells.Add(tempCell5);
                    tempRow.Cells.Add(tempCell6);
                    tempRow.Cells.Add(tempCell7);
                    tempRow.Cells.Add(tempCell8);
                    tempRow.Cells.Add(tempCell9);
                    tempRow.Cells.Add(tempCell10);
                    tempRow.Cells.Add(tempCell11);
                    ProductTable.Rows.Add(tempRow);
                }
                reader.Close();
                con.Close();
            }
            catch (Exception err)
            {
                Message.Text = "Error reading list of products. <br />";
                Message.Text += err.Message + "<br />";
            }
            finally
            {
                con.Close();
                Message.Text += "The Connection is now" + con.State.ToString();
            }
        }
        private void ShowProductList()
        {
            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            string ShowAllProducts = "ShowAllProducts";
            ddlProductList.Items.Clear();
            ListItem firstItem = new ListItem();
            firstItem.Text = "Select a Category";
            firstItem.Value = "0";
            ddlProductList.Items.Add(firstItem);
            ddlProductList.SelectedIndex = 0;
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand(ShowAllProducts, con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader readerSelect;
            try
            {
                con.Open();
                readerSelect = cmd.ExecuteReader();
                while (readerSelect.Read())
                {
                    ListItem newItem = new ListItem();
                    newItem.Text = readerSelect["name"].ToString();
                    newItem.Value = readerSelect["product_ID"].ToString();
                    ddlProductList.Items.Add(newItem);
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
                    con.Close();
                    Message.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }
        private void DeleteProductTable()
        {
            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            string DisplayProductTable = "DisplayProductTable";
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand("DeleteProducts", con);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("@ProductID", ddlProductList.SelectedValue);
            int valueReturned = 0;
            try
            {
                con.Open();
                valueReturned = cmd.ExecuteNonQuery();
                Message.Text = valueReturned.ToString() + " record deleted.";
            }
            catch (Exception err)
            {
                Message.Text = "Error deleting record " + ddlProductList.SelectedValue + "<br />";
                Message.Text += err.Message + "<br />";
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    Message.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }
        private void ddlProductList_SelectedIndexChanged(object sender, EventArgs e)
        { 
            if (ddlProductList.SelectedValue == "0"){
                DeleteProductTable();
                ShowProductList();
            }
        } 
    }
}