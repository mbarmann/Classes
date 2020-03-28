using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MatthewBarmann.Pages
{
    public partial class Calender : System.Web.UI.Page
    {
        protected void MyCalendar_SelectionChanged(object sender, EventArgs e)
        {
            DateTime myDate = new DateTime(2020, 1, 13);
            Message.Text = "";

            if (MyCalender.SelectedDate == myDate)
            {
                Message.Text = "We are closed today!" + "<br>" + "The selected date is " + MyCalender.SelectedDate.ToShortDateString();
            }
            else
            {
                Message.Text = "The selected date is " + MyCalender.SelectedDate.ToShortDateString();
            }
        }
        protected void MyCalendar_DayRender(object sender, DayRenderEventArgs e)
        {
            LiteralControl br = new LiteralControl("<br />");
            
            // All Sundays
            if (e.Day.Date.DayOfWeek == DayOfWeek.Sunday && e.Day.IsOtherMonth) //Sundays that fall on different months
            {
                e.Cell.BackColor = System.Drawing.Color.Tomato; //make the background light red
                e.Cell.ForeColor = System.Drawing.Color.Yellow; //make font yellow
                e.Cell.Controls.Add(new LiteralControl("<br />Closed")); //Display Closed under the date
            }
            else if (e.Day.Date.DayOfWeek == DayOfWeek.Sunday) //for Sundays that fall during current month
            {
                e.Cell.BackColor = System.Drawing.Color.Red; //make the background bright red
                e.Cell.ForeColor = System.Drawing.Color.Yellow; //make font yellow
                e.Cell.Controls.Add(new LiteralControl("<br />Closed")); //Display Closed under the date
            }
            if (e.Day.Date.Day == 20 && e.Day.Date.Month == 1) //check if date is Jan 20th
            {
                Image myImage = new Image(); //create image object
                myImage.AlternateText = "mlk"; //set alterate text incase no image is displayed
                myImage.ImageUrl = "~/Images/mlk.jfif"; //displayed image
                myImage.Height = 30; //image height
                myImage.Width = 16; //image width
                e.Cell.Controls.Add(br); //adds line break after date
                e.Cell.Controls.Add(myImage); //adds my image object
            }
            if (e.Day.Date.Day == 14 && e.Day.Date.Month == 2) //checks if selected date is Feb 14th
            {
                HyperLink myLink = new HyperLink(); //creates my hyperlink object
                myLink.NavigateUrl = "https://www.mms.com/en-us/shop/valentines-day"; //link to be displayed
                myLink.Text = "Valentine's M&Ms"; //Text to display with hyperlink 
                myLink.Target = "_blank"; //opens new tab
                e.Cell.Controls.Add(br); //adds line break after date
                e.Cell.Controls.Add(myLink); //adds my hyperlink object
            }
            if (e.Day.Date.Day == 16 && e.Day.Date.Month == 1) //checks if selected date is Jan 16th
            {
                e.Cell.ForeColor = System.Drawing.Color.Green; //sets font to green
                e.Cell.Controls.Add(new LiteralControl("<br />Kids 10 and Under Enter Free!")); //displays special event message
            }
            if (e.Day.IsOtherMonth) //checks what dates are not in current month
            {
                e.Day.IsSelectable = false; //user can't click on dates outside current month 
            }
        }
    }
}