using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.DataVisualization.Charting;
using System.Web.UI.WebControls;

namespace MatthewBarmann.Pages
{
    public partial class ChartParty : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            DataPoint Hat = new DataPoint(); //create data points for profit table
            DataPoint Sneakers = new DataPoint();
            DataPoint Painting = new DataPoint();
            ProfitChart.Series.Clear(); //clear series out before adding to it
            ProfitChart.Series.Add("Profit"); //add series to chart
            Hat.SetValueY(7.99); //set data point value and name for each
            Hat.AxisLabel = "Hat";
            Sneakers.SetValueY(28.00);
            Sneakers.AxisLabel = "Sneakers";
            Painting.SetValueY(54.99);
            Painting.AxisLabel = "Painting";
            ProfitChart.Series["Profit"].Points.Add(Hat); //add each data point to the series and chart
            ProfitChart.Series["Profit"].Points.Add(Sneakers);
            ProfitChart.Series["Profit"].Points.Add(Painting);
        }
    }
}