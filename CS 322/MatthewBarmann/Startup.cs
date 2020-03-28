using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(MatthewBarmann.Startup))]
namespace MatthewBarmann
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
