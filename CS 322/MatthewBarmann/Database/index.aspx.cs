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
    public partial class index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                ShowCategoryTable();
            }
            else
            {
                for (int i = 1; i < CategoryTable.Rows.Count; i++)
                {
                    CategoryTable.Rows.RemoveAt(i);
                }
                ShowCategoryTable();
            }
        }
        private void ShowCategoryTable()
        {
            string CS = WebConfigurationManager.ConnectionStrings["Barmann"].ConnectionString;
            string DisplayCategoryTable = "DisplayCategoryTable";
            CategoryTable.Controls.Clear();
            SqlConnection con = new SqlConnection(CS);
            SqlCommand cmd = new SqlCommand(DisplayCategoryTable, con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader reader; TableCell tempCell1, tempCell2, tempCell3, tempCell4, tempCell5;
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
                    tempCell1.Text = reader["Id"].ToString();
                    tempCell2 = new TableCell();
                    tempCell2.Text = reader["name"].ToString();
                    tempCell3 = new TableCell();
                    tempCell3.Text = reader["description"].ToString();
                    tempCell4 = new TableCell();
                    System.Web.UI.WebControls.Image CatPicture =new System.Web.UI.WebControls.Image();
                    CatPicture.Width = 100; CatPicture.Height = 100;
                    CatPicture.ImageUrl = String.Format(ImagePath, 0, reader["image"].ToString()); 
                    tempCell4.Controls.Add(CatPicture);
                    tempCell5 = new TableCell();
                    System.Web.UI.WebControls.Image CatThumb = new System.Web.UI.WebControls.Image();
                    CatThumb.Width = 50; CatThumb.Height = 50;
                    CatThumb.ImageUrl = String.Format(ImagePath, 0, reader["thumbnail"].ToString()); 
                    tempCell5.Controls.Add(CatThumb);
                    tempRow.Cells.Add(tempCell1);
                    tempRow.Cells.Add(tempCell2);
                    tempRow.Cells.Add(tempCell3);
                    tempRow.Cells.Add(tempCell4);
                    tempRow.Cells.Add(tempCell5);
                    CategoryTable.Rows.Add(tempRow);
                }
                reader.Close();
                con.Close();
            }
            catch (Exception err)
            {
                Message.Text = "Error reading list of categories. <br />";
                Message.Text += err.Message + "<br />";
            }
            finally
            {
                con.Close();
                Message.Text += "The Connection is now" + con.State.ToString();
            }
        }
    }
}